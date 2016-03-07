/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 20:10:34 by nromptea          #+#    #+#             */
/*   Updated: 2016/03/07 16:59:49 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		put_thing(t_param *param)
{
	int		i;
	int		j;
	float	xpix;
	float	ypix;
	t_pnt	pnt;

	i = 0;
	while (i < param->map.nb_line)
	{
		j = 0;
		while (j < param->map.nb_col)
		{
			xpix = get_xy_pix(&ypix, i, j, param);
			mlx_pixel_put(param->mlx, param->win, xpix, ypix, 0x00FFFFFF);
			pnt.i = i;
			pnt.j = j;
			draw_line(param, xpix, ypix, pnt);
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
