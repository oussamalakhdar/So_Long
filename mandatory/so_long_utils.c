/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olakhdar <olakhdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:44:44 by olakhdar          #+#    #+#             */
/*   Updated: 2022/03/23 11:23:06 by olakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	checkopen(t_data *ptr)
{
	if (ptr->fd == -1)
	{
		ft_printf("This map is not exist!\n");
		exit(1);
	}
}

char	**ft_buffer(t_data *bf, char **argv)
{
	char	*str;
	char	*buffer;
	char	**s;

	str = ft_strdup("");
	buffer = NULL;
	bf->fd = open(argv[1], O_RDONLY);
	checkopen(bf);
	buffer = get_next_line(bf->fd);
	if (buffer == '\0')
	{
		ft_printf("Empty Map!\n");
		exit(1);
	}
	while (buffer)
	{
		str = ft_strjoin(str, buffer);
		free(buffer);
		buffer = get_next_line(bf->fd);
	}
	free(buffer);
	s = ft_split(str, '\n');
	free(str);
	close(bf->fd);
	return (s);
}

void	func2(t_data *t, int i, int j)
{
	if (t->map[0][j] != '1')
	{
		ft_printf("Map Invalid! Please Check It Out.\n");
		exit(1);
	}
	if (t->map[t->nbrlines - 1][j] != '1')
	{
		ft_printf("Map Invalid! Please Check It Out.\n");
		exit(1);
	}
	if (t->map[i][j] != '1' && t->map[i][j] != '0'
		&& t->map[i][j] != 'C' && t->map[i][j] != 'P' && t->map[i][j] != 'E')
	{
		ft_printf("Map Invalid! Please Check It Out.\n");
		exit(1);
	}
	if (t->map[i][j] == 'E')
	{
		t->yexit = i;
		t->xexit = j;
	}
}

void	func1(t_data *p, int i)
{
	if (ft_strlen(p->map[0]) != ft_strlen(p->map[i]))
	{
		ft_printf("Map Invalid! Please Check It Out.\n");
		exit(1);
	}
	if (p->map[i][0] != '1')
	{
		ft_printf("Map Invalid! Please Check It Out.\n");
		exit(1);
	}
	if (p->map[i][ft_strlen(p->map[0]) - 1] != '1')
	{
		ft_printf("Map Invalid! Please Check It Out.\n");
		exit(1);
	}
}

void	ft_checkmap(t_data *c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (c->map[i])
	{
		j = 0;
		func1(c, i);
		while (c->map[i][j])
		{
			func2(c, i, j);
			if (c->map[i][j] == 'P')
			{
				c->iplayer = i;
				c->jplayer = j;
			}
			j++;
		}
		i++;
	}
}
