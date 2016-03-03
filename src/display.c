/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 18:08:38 by nromptea          #+#    #+#             */
/*   Updated: 2016/03/03 16:11:34 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		define_color(int **tab, int i, int j)
{
	if (tab[i][j] <= 0)
		return (0x00FFFFFF);
	if (tab[i][j] > 0 && tab[i][j] <= 5)
		return (0x000000FF);
	if (tab[i][j] > 5 && tab[i][j] <= 10)
		return (0x00FF0000);
	return (0x00FFFF00);
}

int		get_xy_pix(int *ynat, int i, int j, t_param *param)
{
	int		xpix;
	int		ypix;
	float	xpr;
	float	ypr;

	xpr = (j + 1) - (SQRT2S2 * (i + 1));
	ypr = param->map.tab[i][j] - (SQRT2S2 * (i + 1));
	xpix = (int)roundf(xpr * param->calcul.pasx + param->calcul.xori);
	ypix = (int)roundf(ypr * param->calcul.pasy + param->calcul.yori);
	*ynat = HAUTEUR - ypix;
	return (xpix);
}

int		put_thing(t_param *param)
{
	int		i;
	int		j;
	int		xpix;
	int		ypix;
	int		color;

	i = 0;
	while (i < param->map.nb_line)
	{
		j = 0;
		while (j < param->map.nb_col)
		{
			xpix = get_xy_pix(&ypix, i, j, param);
			color = define_color(param->map.tab, i, j);
			mlx_pixel_put(param->mlx, param->win, xpix, ypix, color);
			draw_line(param, xpix, ypix, i, j);
			j++;
		}
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
	{
		put_thing(param);
	}
	return (0);
}
