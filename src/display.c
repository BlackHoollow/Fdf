/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 18:08:38 by nromptea          #+#    #+#             */
/*   Updated: 2016/02/24 19:19:31 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		define_color(int **tab, int i, int j)
{
	if (tab[i][j] == 0)
		return (0x00FFFFFF);
	if (tab[i][j] > 0 && tab[i][j] < 5)
		return (0x000000FF);
	if (tab[i][j] > 5 && tab[i][j] < 10)
		return (0x0000FF00);
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
			mlx_pixel_put(param->mlx, param->win, x + j, y + , color);
			j++;
		}
		i++;
	}
}

int		put_thing(t_param *param)
{
	int		x;
	int		i;
	int		y;
	int		j;
	int		color;

	y = 200;
	i = 0;
	while (i < param->map.nb_line)
	{
		x = 200;
		j = 0;
		while (j < param->map.nb_col)
		{
			color = define_color(param->map.tab, i, j);
			big_pixel(param, x, y, color);
			j++;
			x = x + 20;
		}
		i++;
		y = y + 20;
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
