/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 15:17:20 by nromptea          #+#    #+#             */
/*   Updated: 2016/03/06 19:52:39 by mbinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"
# include "mlx.h"
# include "math.h"

# define HAUTEUR 1000
# define LARGEUR 1000
# define SQRT2S2 0.7071067812

typedef struct	s_map
{
	int			nb_col;
	int			nb_line;
	int			zmin;
	int			zmax;
	int			**tab;
}				t_map;

typedef struct	s_calcul
{
	float		xpmin;
	float		xpmax;
	float		ypmin;
	float		ypmax;
	int			xori;
	int			yori;
	int			pasx;
	int			pasy;
}				t_calcul;

typedef struct	s_param
{
	void		*mlx;
	void		*win;
	t_map		map;
	t_calcul	calcul;
}				t_param;

/*
** parse2.c
*/

t_map			*count_line_col(int fd, t_map *map);
t_map			*split_tab(t_map *map, int fd);
void			parsing(char *argv, t_map *map);
t_map			*get_altitude(t_map *map);

/*
** core.c
*/

void			ft_exit(char *str);
void			print_tab(int **tab, int nb_col, int nb_line);
int				main(int argc, char **argv);

/*
**	display.c
*/

int				define_color(int **tab, int i, int j);
float			get_xy_pix(float *ynat, int i, int j, t_param *param);
int				put_thing(t_param *param);
int				my_key_func(int keycode, void *param);

/*
**	calcul.c
*/

void			prime(t_map *map, t_calcul *calcul);
void			pas(t_calcul *calcul);
void			origine(t_calcul *calcul);
void			calcul_all(t_map *map, t_calcul *calcul);

/*
**	line.c
*/

void			draw_line(t_param *param, int xpix, int ypix, int i, int j);
void			draw_right(t_param *param, int xpix, int ypix, int i, int j);
void			draw_down(t_param *param, int xpix, int ypix, int i, int j);

#endif
