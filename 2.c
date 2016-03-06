/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 20:16:48 by nromptea          #+#    #+#             */
/*   Updated: 2016/03/06 20:17:00 by nromptea         ###   ########.fr       */
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
