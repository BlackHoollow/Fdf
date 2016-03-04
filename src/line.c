/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 12:24:39 by nromptea          #+#    #+#             */
/*   Updated: 2016/03/04 18:26:50 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_param *param, int xpix, int ypix, int i, int j)
{
	draw_right(param, xpix, ypix, i, j);
//	draw_down(parma, xpix, ypix), i, j;
}

void	draw_right(t_param *param, int xpix, int ypix, int i, int j)
{
	int		x;
	int		y;
	int		x1;
	int		y1;

	x = xpix;
	if (j == param->map.nb_col - 1)
		return ;
	x1 = get_xy_pix(&y1, i + 1, j, param);
	y = ((y1 - ypix) / (x1 - xpix));
	while (x < x1)
	{
		mlx_pixel_put(param->mlx, param->win, x, y, 0x00FFFFFF);
		x++;
	}
}
