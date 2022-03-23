/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olakhdar <olakhdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:18:32 by olakhdar          #+#    #+#             */
/*   Updated: 2022/03/23 11:21:12 by olakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_destroywin(int keycode)
{
	(void)keycode;
	ft_printf("Exit!\n");
	exit(0);
}

void	fnct(t_data *var)
{
	var->move += 1;
	mlx_clear_window(var->mlx, var->win);
	drawimage(var);
	ft_printf("Number of movement = %d\n", var->move);
}

void	keyextra(t_data *var)
{
	if (var->key == 0 || var->key == 123)
	{
		var->xplayer -= 1;
		fnct(var);
	}
	if (var->key == 13 || var->key == 126)
	{
		var->yplayer -= 1;
		fnct(var);
	}
	if (var->key == 1 || var->key == 125)
	{
		var->yplayer += 1;
		fnct(var);
	}
	if (var->key == 2 || var->key == 124)
	{
		var->xplayer += 1;
		fnct(var);
	}
}

int	key_hook(int keycode, t_data *vars)
{
	vars->key = keycode;
	if (keycode == 53)
	{
		ft_printf("Exit!\n");
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	if (keycode != 53 && keycode != 13
		&& keycode != 0 && keycode != 1 && keycode != 2)
	{
		vars->xplayer += 0;
		vars->yplayer += 0;
		mlx_clear_window(vars->mlx, vars->win);
		drawimage(vars);
	}
	keyextra(vars);
	return (0);
}

int	ft_count(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
