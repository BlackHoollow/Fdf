/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 18:08:38 by nromptea          #+#    #+#             */
/*   Updated: 2016/02/26 18:44:53 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define RC2S2 0.70710678118
#define RC2S3 0.47140452079
#define S1RC6 0.40824829046
#include <stdio.h>

int		define_color(int **tab, int i, int j)
{
	if (tab[i][j] == 0)
		return (0x00FFFFFF);
	if (tab[i][j] > 0 && tab[i][j] < 5)
		return (0x000000FF);
	if (tab[i][j] > 5 && tab[i][j] < 10)
		return (0x00FF0000);
	else
		return (0x00FFFF00);
}

void	big_pixel(t_param *param, int x, int y, int color)
{
	int		i;
	int		j;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			mlx_pixel_put(param->mlx, param->win, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

int		put_thing(t_param *param)
{
	int		x;
	int		y;
	int		i;
	int		j;
	float	a;
	float	b;
	int		color;
	
	y = 0;
	i = 0;
	while (i < param->map.nb_line)
	{
		x = 0;
		j = 0;
		while (j < param->map.nb_col)
		{
			a =  RC2S2 * (x - y);
			b = (RC2S3 * (param->map.tab[i][j])) - (S1RC6 * (x + y));
			x = (int)roundf(a);
			y = (int)roundf(b);
			/*x = x - param->map.tab[i][j];
			y = y - param->map.tab[i][j];
			x = x - y;
			y = x + (y / 2);*/
			printf("a = %f x = %d \t b = %f y = %d\n", a, x, b, y);
			color = define_color(param->map.tab, i, j);
//			big_pixel(param, x, y, color);
			mlx_pixel_put(param->mlx, param->win, x, -y, (define_color(param->map.tab, i, j)));
			j++;
			x = x + 20;
		}
		y = y + 20;
		i++;
	}
	return (0);
}

int		my_key_func(int keycode, void *param)
{
	ft_putstr("Key event : ");
	ft_putnbr(keycode);
	ft_putchar('\n');
	if (keycode == 53)
		ft_exit("quit");
	if (keycode == 37)
		put_thing(param);
	return (0);
}
