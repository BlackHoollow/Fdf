/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 20:17:03 by nromptea          #+#    #+#             */
/*   Updated: 2016/03/06 20:17:21 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		put_thing(t_param *param)
{
	int		i;
	int		j;
	float	xpix;
	float	ypix;
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
