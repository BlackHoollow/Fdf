/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 16:59:39 by nromptea          #+#    #+#             */
/*   Updated: 2016/02/24 17:59:37 by nromptea         ###   ########.fr       */
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

int		define_color(int **tab, int i, int j)
{
	if (tab[i][j] == 0)
		return (0x00FFFFFF);
	if (tab[i][j] > 0 && tab[i][j] < 5)
		return (0x000000FF);
	if (tab[i][j] > 5 && tab[i][j] < 10)
		return (0x0000FF00);
	else
		return (0x00FFFF00);
}

int		put_thing(t_param *param)
{
	int		x;
	int		i;
	int		y;
	int		j;
	int		color;

	y = 100;
	i = 0;
	while (i < param->map.nb_line)
	{
		x = 100;
		j = 0;
		while (j < param->map.nb_col)
		{
			color = define_color(param->map.tab, i, j);
			mlx_pixel_put(param->mlx, param->win, x, y, color);
			j++;
			x = x + 20;
		}
		i++;
		y = y + 20;
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

int		main(int argc, char **argv)
{
	t_map	map;
	t_param	param;

	if (argc != 2)
		ft_exit("Erreur d'arguments");
	parsing(argv[1], &map);
	param.mlx = mlx_init();
	param.win = mlx_new_window(param.mlx, 800, 800, "mlx 42");
	param.map = map;
	mlx_key_hook(param.win, my_key_func, &param);

	mlx_loop(param.mlx);
	return (0);
}
