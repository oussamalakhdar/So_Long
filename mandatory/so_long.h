/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olakhdar <olakhdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:41:05 by olakhdar          #+#    #+#             */
/*   Updated: 2022/03/23 18:51:17 by olakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdarg.h>
# define BUFFER_SIZE 1
# define X 100
# define Y 100

typedef struct s_data {
	void	*mlx;
	void	*win;
	char	**map;
	int		key;
	void	*img1;
	void	*img2;
	void	*img3;
	void	*img4;
	void	*img5;
	char	*wall;
	char	*collectible;
	char	*player;
	char	*exit;
	char	*empty;
	int		move;
	int		fd;
	int		xplayer;
	int		yplayer;
	int		nbrlines;
	int		nbcollectible;
	int		xexit;
	int		yexit;
	int		jplayer;
	int		iplayer;
	int		*xtable;
	int		*ytable;
	int		xtab;
	int		ytab;
}	t_data;

char	**ft_buffer(t_data *bf, char **argv);
void	ft_checkmap(t_data *c);
int		checkcollect(t_data *check, int a, int b);
void	drawcollect(t_data *c);
void	drawplayer(t_data *p);
int		key_hook(int keycode, t_data *vars);
int		ft_count(char **s);
int		ft_destroywin(int keycode);
char	*get_next_line(int fd);
char	**ft_split(char const *s, char c);
char	*ft_strdup(char *s1);
char	*ft_substr(char *s, int start, int len);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *str);
int		ft_strchr(char *s, char c);
void	drawimage(t_data *f);
void	ft_countcollectible(t_data *coll);
void	tableallocation(t_data *ptr);
void	checkxpm(t_data *ptr);
int		ft_printf(char *format, ...);
int		checkcharacters(char *str);
void	checkbuffer(char *buffer);

#endif