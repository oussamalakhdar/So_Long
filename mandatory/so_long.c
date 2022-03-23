/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olakhdar <olakhdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 21:18:37 by olakhdar          #+#    #+#             */
/*   Updated: 2022/03/23 13:59:38 by olakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_countcollectible(t_data *coll)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	coll->nbcollectible = 0;
	while (coll->map[i])
	{
		j = 0;
		while (coll->map[i][j])
		{
			if (coll->map[i][j] == 'C')
				coll->nbcollectible++;
			j++;
		}
		i++;
	}
}

void	checkwall(t_data *w, int i, int j)
{
	mlx_put_image_to_window(w->mlx, w->win, w->img1, X * j, Y * i);
	if (X * j == 100 * (w->jplayer + w->xplayer)
		&& Y * i == 100 * (w->iplayer + w->yplayer))
	{
		if (w->key == 0 || w->key == 123)
		{
			w->xplayer += 1;
			w->move -= 1;
		}
		if (w->key == 13 || w->key == 126)
		{
			w->yplayer += 1;
			w->move -= 1;
		}
		if (w->key == 1 || w->key == 125)
		{
			w->yplayer -= 1;
			w->move -= 1;
		}
		if (w->key == 2 || w->key == 124)
		{
			w->xplayer -= 1;
			w->move -= 1;
		}
	}
}

void	drawimage(t_data *f)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	ft_checkmap(f);
	while (i < f->nbrlines)
	{
		j = 0;
		while (f->map[i][j])
		{
			mlx_put_image_to_window(f->mlx, f->win, f->img5, X * j, Y * i);
			if (f->map[i][j] == '1')
				checkwall(f, i, j);
			if (f->map[i][j] == 'E')
				mlx_put_image_to_window(f->mlx, f->win, f->img4, X * j, Y * i);
			j++;
		}
		i++;
	}
	drawplayer(f);
	drawcollect(f);
}

void	put_image(t_data *vr, char **argv)
{
	int		w;
	int		h;

	vr->xplayer = 0;
	vr->yplayer = 0;
	vr->move = 0;
	vr->map = ft_buffer(vr, argv);
	vr->nbrlines = ft_count(vr->map);
	ft_countcollectible(vr);
	tableallocation(vr);
	vr->xtab = 0;
	vr->ytab = 0;
	vr->win = mlx_new_window(vr->mlx, 100 * ft_strlen(vr->map[0]),
			100 * vr->nbrlines, "so_long");
	vr->img1 = mlx_xpm_file_to_image(vr->mlx, vr->wall, &w, &h);
	vr->img2 = mlx_xpm_file_to_image(vr->mlx, vr->collectible, &w, &h);
	vr->img3 = mlx_xpm_file_to_image(vr->mlx, vr->player, &w, &h);
	vr->img4 = mlx_xpm_file_to_image(vr->mlx, vr->exit, &w, &h);
	vr->img5 = mlx_xpm_file_to_image(vr->mlx, vr->empty, &w, &h);
	checkxpm(vr);
	if (vr->move == 0)
		ft_printf("Number of movement = %d\n", vr->move);
	mlx_key_hook(vr->win, key_hook, vr);
	mlx_hook(vr->win, 17, 0, ft_destroywin, (void *)0);
	drawimage(vr);
}

int	main(int argc, char **argv)
{
	t_data	v;

	if (argc == 2)
	{
		v.mlx = mlx_init();
		v.wall = ft_strdup("../images/wall.xpm");
		v.collectible = ft_strdup("../images/collectible.xpm");
		v.player = ft_strdup("../images/player.xpm");
		v.exit = ft_strdup("../images/exit.xpm");
		v.empty = ft_strdup("../images/empty.xpm");
		if (!v.mlx || !v.wall || !v.collectible
			|| !v.player || !v.exit || !v.empty)
		{
			perror("Allocation Failed!\n");
			exit(1);
		}
		put_image(&v, argv);
		mlx_loop(v.mlx);
	}
	else
		return (0);
}
