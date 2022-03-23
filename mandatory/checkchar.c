/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkchar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olakhdar <olakhdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 18:45:50 by olakhdar          #+#    #+#             */
/*   Updated: 2022/03/23 18:52:21 by olakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	checkcharacters(char *str)
{
	if (ft_strchr(str, 'E') == -1 || ft_strchr(str, 'C') == -1
		|| ft_strchr(str, 'P') == -1)
	{
		perror("Some Characters Are Missed!");
		exit(1);
	}
	return (0);
}

void	checkbuffer(char *buffer)
{
	if (buffer == '\0')
	{
		ft_printf("Empty Map!\n");
		exit(1);
	}
}
