/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olakhdar <olakhdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 18:28:09 by olakhdar          #+#    #+#             */
/*   Updated: 2022/03/23 10:12:13 by olakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	drawsprite(t_data *ptr)
{
	if (ptr->xsprite == ft_strlen(ptr->map[0]) - 1)
		ptr->xsprite = 1;
	ptr->ysprite = ptr->nbrlines / 2;
	mlx_clear_window(ptr->mlx, ptr->win);
	drawimage(ptr);
	mlx_put_image_to_window(ptr->mlx, ptr->win,
		ptr->img6, X * ptr->xsprite, Y * ptr->ysprite);
	ptr->xsprite++;
	usleep(90000);
	return (0);
}
