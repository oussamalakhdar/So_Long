/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olakhdar <olakhdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 11:52:15 by olakhdar          #+#    #+#             */
/*   Updated: 2022/03/16 20:45:30 by olakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	checkcollect(t_data *check, int a, int b)
{
	int	i;

	i = 0;
	while (check->xtable[i] && check->ytable[i])
	{
		if (check->xtable[i] == X * b && check->ytable[i] == Y * a)
			return (1);
		i++;
	}
	return (0);
}

void	drawcollect(t_data *c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < c->nbrlines)
	{
		j = 0;
		while (c->map[i][j])
		{
			if (c->map[i][j] == 'C')
			{
				if (checkcollect(c, i, j) == 0)
					mlx_put_image_to_window(c->mlx, c->win, c->img2,
						X * j, Y * i);
			}
			j++;
		}
		i++;
	}
}

void	stocktable(t_data *s, int i, int j)
{
	if (X * j == 100 * (s->jplayer + s->xplayer)
		&& Y * i == 100 * (s->iplayer + s->yplayer))
	{
		if (checkcollect(s, i, j) == 0)
		{
			s->xtable[s->xtab++] = X * j;
			s->ytable[s->ytab++] = Y * i;
			s->nbcollectible--;
		}
	}
}

void	ft_drawplayer(t_data *e, int i, int j)
{
	if (X * (j + e->xplayer) == e->xexit * 100
		&& Y * (i + e->yplayer) == e->yexit * 100
		&& e->nbcollectible == 0)
	{	
		printf("Nice play! You Won.\n");
		exit(0);
	}
	else
		mlx_put_image_to_window(e->mlx, e->win, e->img3,
			X * (j + e->xplayer), Y * (i + e->yplayer));
}

void	drawplayer(t_data *p)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < p->nbrlines)
	{
		j = 0;
		while (p->map[i][j])
		{
			if (p->map[i][j] == 'C')
				stocktable(p, i, j);
			if (p->map[i][j] == 'P')
				ft_drawplayer(p, i, j);
			j++;
		}
		i++;
	}
}
