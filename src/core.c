/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 16:59:39 by nromptea          #+#    #+#             */
/*   Updated: 2016/03/03 09:31:20 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_exit(char *str)
{
	ft_putendl(str);
	exit(1);
}

void	print_tab(int **tab, int nb_col, int nb_line)
{
	int		i;
	int		j;

	i = 0;
	while (i < nb_line)
	{
		j = 0;
		while (j < nb_col)
		{
			ft_putnbr(tab[i][j]);
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int		main(int argc, char **argv)
{
	t_map		map;
	t_param		param;
	t_calcul	calcul;

	if (argc != 2)
		ft_exit("Erreur d'arguments");
	parsing(argv[1], &map);
	param.mlx = mlx_init();
	param.win = mlx_new_window(param.mlx, HAUTEUR, LARGEUR, "mlx 42");
	param.map = map;
	calcul_all(&map, &calcul);
	param.calcul = calcul;
	mlx_key_hook(param.win, my_key_func, &param);
	mlx_loop(param.mlx);
	return (0);
}
