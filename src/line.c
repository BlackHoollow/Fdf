/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 12:24:39 by nromptea          #+#    #+#             */
/*   Updated: 2016/03/25 17:38:13 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_param *param, int xpix, int ypix, t_pnt pnt)
{
	draw_right(param, xpix, ypix, pnt);
	draw_down(param, xpix, ypix, pnt);
}

void	draw_right(t_param *param, int xpix, int ypix, t_pnt pnt)
{
	float	x;
	float	y;
	float	x1;
	float	y1;

	if (pnt.j == param->map.nb_col - 1)
		return ;
	x1 = get_xy_pix(&y1, pnt.i, pnt.j + 1, param);
	if ((y1 - ypix) / (x1 - xpix) > -1 && (y1 - ypix) / (x1 - xpix) < 1)
	{
		x = xpix;
		while (x < x1)
		{
			y = ypix + (y1 - ypix) / (x1 - xpix) * (x - xpix);
			mlx_pixel_put(param->mlx, param->win, x, y, 0x00FFFFFF);
			x = x + 1;
		}
	}
	else
	{
		draw_right_bis(param, xpix, ypix, pnt);
	}
}

void	draw_right_bis(t_param *param, int xpix, int ypix, t_pnt pnt)
{
	float	y;
	float	x;
	float	x1;
	float	y1;

	x1 = get_xy_pix(&y1, pnt.i, pnt.j + 1, param);
	y = ypix;
	while (y < y1)
	{
		x = xpix + (x1 - xpix) / (y1 - ypix) * (y - ypix);
		mlx_pixel_put(param->mlx, param->win, x, y, 0x00FFFFFF);
		y = y + 1;
	}
	y = y1;
	while (y < ypix)
	{
		x = xpix + (x1 - xpix) / (y1 - ypix) * (y - ypix);
		mlx_pixel_put(param->mlx, param->win, x, y, 0x00FFFFFF);
		y = y + 1;
	}
}

void	draw_down(t_param *param, int xpix, int ypix, t_pnt pnt)
{
	float	x;
	float	y;
	float	x1;
	float	y1;

	if (pnt.i == param->map.nb_line - 1)
		return ;
	x1 = get_xy_pix(&y1, pnt.i + 1, pnt.j, param);
	y = ypix;
	while (y < y1)
	{
		x = xpix + (x1 - xpix) / (y1 - ypix) * (y - ypix);
		mlx_pixel_put(param->mlx, param->win, x, y, 0x00FFFFFF);
		y = y + 1;
	}
	y = y1;
	while (y < ypix)
	{
		x = xpix + (x1 - xpix) / (y1 - ypix) * (y - ypix);
		mlx_pixel_put(param->mlx, param->win, x, y, 0x00FFFFFF);
		y = y + 1;
	}
}
