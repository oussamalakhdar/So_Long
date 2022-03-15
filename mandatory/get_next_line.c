/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olakhdar <olakhdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:57:22 by olakhdar          #+#    #+#             */
/*   Updated: 2022/03/08 08:59:18 by olakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_rest(char **stock)
{
	int		j;
	char	*tmp;
	char	*line;

	j = ft_strchr(*stock, '\n');
	line = ft_substr(*stock, 0, j + 1);
	tmp = *stock;
	*stock = ft_substr(*stock, j + 1, ft_strlen(*stock + j + 1));
	free(tmp);
	return (line);
}

char	*ft_line(char **stock)
{
	char	*line;

	if (ft_strchr(*stock, '\n') != -1)
		line = ft_rest(stock);
	else if ((*stock)[0] == '\0')
	{
		free(*stock);
		*stock = NULL;
		return (NULL);
	}
	else
	{
		line = ft_substr(*stock, 0, ft_strlen(*stock));
		free(*stock);
		*stock = NULL;
	}
	return (line);
}

void	ft_stock(char **stock, int fd)
{
	int		i;
	char	*buffer;

	i = 0;
	while (ft_strchr(*stock, '\n') == -1)
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buffer == NULL)
			return ;
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1 || i == 0)
		{
			free(buffer);
			break ;
		}
		buffer[i] = '\0';
		*stock = ft_strjoin(*stock, buffer);
		free(buffer);
	}
}

char	*get_next_line(int fd)
{
	static char	*stock;

	if (!stock)
	{
		stock = ft_strdup("");
		if (!stock)
			return (NULL);
	}
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ft_stock(&stock, fd);
	return (ft_line(&stock));
}
