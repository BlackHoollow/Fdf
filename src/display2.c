/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 20:10:34 by nromptea          #+#    #+#             */
/*   Updated: 2016/03/06 20:21:35 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	get_xy_pix(float *ynat, int i, int j, t_param *param)
{
	float	xpix;
	float	ypix;
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
	float	xpix;
	float	ypix;

	i = 0;
	while (i < param->map.nb_line)
	{
		j = 0;
		while (j < param->map.nb_col)
		{
			xpix = get_xy_pix(&ypix, i, j, param);
			mlx_pixel_put(param->mlx, param->win, xpix, ypix, 0x00FFFFFF);
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
