/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 12:24:39 by nromptea          #+#    #+#             */
/*   Updated: 2016/03/05 19:14:47 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_param *param, int xpix, int ypix, int i, int j)
{
	draw_right(param, xpix, ypix, i, j);
	draw_down(param, xpix, ypix, i, j);
}

void	draw_right(t_param *param, int xpix, int ypix, int i, int j)
{
	float	x;
	float	y;
	float	x1;
	float	y1;

	if (j == param->map.nb_col - 1)
		return ;
	x1 = get_xy_pix(&y1, i, j + 1, param);
	if ((y1 - ypix) / (x1 - xpix) > -1 && (y1 - ypix) / (x1 - xpix) < 1)
	{
		x = xpix;
		while (x < x1)
		{
			y = ypix + (y1 - ypix)/(x1 - xpix) * (x - xpix);
			mlx_pixel_put(param->mlx, param->win, x, y, 0x00FFFFFF);
			x = x + 1;
		}
	}
	else
	{
		y = ypix;
		while (y < y1)
		{
			x = xpix + (x1 - xpix)/(y1 - ypix) * (y - ypix);
			mlx_pixel_put(param->mlx, param->win, x, y, 0x00FFFFFF);
			y = y + 1;
		}
	}
}

void	draw_down(t_param *param, int xpix, int ypix, int i , int j)
{
	float	x;
	float	y;
	float	x1;
	float	y1;

	if (i == param->map.nb_line - 1)
		return ;
	x1 = get_xy_pix(&y1, i + 1, j, param);
	y = ypix;
	while (y < y1)
	{
		x = xpix + (x1 - xpix)/(y1 - ypix) * (y - ypix);
		mlx_pixel_put(param->mlx, param->win, x, y, 0x00FFFFFF);
		y = y + 1;
	}
}
