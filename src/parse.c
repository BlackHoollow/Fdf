/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 15:10:46 by nromptea          #+#    #+#             */
/*   Updated: 2016/02/22 20:39:01 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	count_line_col(int fd, int *nb_col, int *nb_line)
{
	char	*line;
	char	**split;
	int		i;

	while (get_next_line(fd, &line) == 1)
	{
		i = 0;
		split = ft_strsplit(line, ' ');
		while (split[i] != NULL)
			i++;
		*nb_line = *nb_line + 1;
		if (i > *nb_col)
			*nb_col = i;
	}
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

int		check(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
	}
	return (1);
}

int		**split_tab(int **tab, int nb_col, int fd)
{
	char	**split;
	char	*line;
	int		i;
	int		j;

	i = 0;
	while (get_next_line(fd, &line) == 1)
	{
		j = 0;
		if (check(line) == 0)
			ft_exit("Il ne faut que des nombres dans le fichier");
		tab[i] = (int *)malloc(sizeof(int) * (nb_col));
		tab[i] = fill_it(nb_col, tab[i]);
		tab[i][nb_col] = -2;
		split = ft_strsplit(line, ' ');
		while (split[j] != NULL)
		{
			tab[i][j] = ft_getnbr(split[j]);
			j++;
		}
		i++;
	}
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
	if (fd = open(argv, O_RDONLY) = -1)
		ft_exit("Erreur de lecture");
	count_line_col(fd, &nb_col, &nb_line);
	tab = (int **)malloc(sizeof(int *) * nb_line);
	tab[nb_line] = NULL;
	close(fd);
	fd = open(argv, O_RDONLY);
	tab = split_tab(tab, nb_col, fd);
	close(fd);
	print_tab(tab, nb_col, nb_line);
	return (tab);
}
