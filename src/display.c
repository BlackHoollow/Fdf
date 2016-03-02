/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 18:08:38 by nromptea          #+#    #+#             */
/*   Updated: 2016/03/02 22:59:08 by nromptea         ###   ########.fr       */
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
		return (0x00FF0000);
	else
		return (0x00FFFF00);
}

/*void	big_pixel(t_param *param, int x, int y, int color)
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
}*/

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

	int		i;
	int		j;
	int		xpix;
	int		ypix;

	i = 0;
	while (i < param->map.nb_line)
	{
		j = 0;
		while (j < param->map.nb_col)
		{
			xpix = get_xy_pix(&ypix, i, j, param);
			mlx_pixel_put(param->mlx, param->win, xpix, ypix, 0x00FFFFFF);
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
		put_thing(param);
	return (0);
}
