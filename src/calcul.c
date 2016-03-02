/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 18:25:33 by nromptea          #+#    #+#             */
/*   Updated: 2016/03/02 21:44:25 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	prime(t_map *map, t_calcul *calcul)
{
	calcul->xpmin = 1 - (map->nb_line * SQRT2S2);
	calcul->xpmax = map->nb_col - SQRT2S2;
	calcul->ypmin = map->zmin - (map->nb_line * SQRT2S2);
	calcul->ypmax = map->zmax - SQRT2S2;
}

void	pas(t_calcul *calcul)
{
	calcul->pasx = (int)roundf(HAUTEUR / (calcul->xpmax - calcul->xpmin));
	calcul->pasy = (int)roundf(LARGEUR / (calcul->ypmax - calcul->ypmin));
}

void	origine(t_calcul *calcul)
{
	calcul->xori = 1 - (int)roundf(calcul->xpmin * calcul->pasx);
	calcul->yori = 1 - (int)roundf(calcul->ypmin * calcul->pasy);
}

void	calcul_all(t_map *map, t_calcul *calcul)
{
	prime(map, calcul);
	pas(calcul);
	origine(calcul);
}

/*void	print_res(t_calcul *calcul)
{
	printf("x' va de : %f a : %f\n", calcul->xpmin,calcul->xpmax);
	printf("y' va de : %f a : %f\n", calcul->ypmin, calcul->ypmax);
	printf("origine x = %d\norigine y = %d\n", calcul->xori, calcul->yori);
	printf("pas de x = %d\npas de y = %d\n", calcul->pasx, calcul->pasy);
}*/
