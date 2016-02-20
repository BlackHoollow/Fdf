/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 15:10:46 by nromptea          #+#    #+#             */
/*   Updated: 2016/02/20 19:14:14 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <stdio.h>

void	print_tab(int **tab)
{
	int		i;
	int		j;

	i = 0;
	while (tab[i] != NULL)
	{
		j = 0;
		while (tab[i][j] != -2)
		{
			ft_putnbr(tab[i][j]);
			ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}

void	count_line_col(int fd, int *nb_col, int *nb_line)
{
	char	*line;

	while (get_next_line(fd, &line) == 1)
	{
		if ((int)ft_strlen(line) > *nb_col)
			*nb_col = ft_strlen(line);
		*nb_line = *nb_line + 1;
	}
	close(fd);
	printf("%d ......... %d\n", *nb_col, *nb_line);
}

int		*fill_it(int nb, int *tab)
{
	int		i;

	i = 0;
	while (i < nb)
	{
		tab[i] = -1;
		i++;
	}
	return (tab);
}

int		**split_tab(int **tab, int nb_col, int fd)
{
	char	**split;
	char	*line;
	int		i;

	i = 0;
	while (get_next_line(fd, &line) == 1)
	{
		*tab = (int *)malloc(sizeof(int) * nb_col);
		*tab = fill_it(nb_col, *tab);
		*tab[nb_col] = -2;
		split = ft_strsplit(line, ' ');
		*tab[i] = ft_getnbr(split[i]);
		i++;
	}
	close(fd);
	return (tab);
}

int		**parsing(char *argv)
{
	int		**tab;
	int		fd;
	int		nb_line;
	int		nb_col;

	nb_line = 0;
	nb_col = 0;
	fd = open(argv, O_RDONLY);
	ft_putendl("salut");
	count_line_col(fd, &nb_col, &nb_line);
	tab = (int **)malloc(sizeof(int *) * nb_line);
	tab[nb_line] = NULL;
	fd = open(argv, O_RDONLY);
	tab = split_tab(tab, nb_col, fd);
	return (tab);
}
