/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 15:10:34 by nromptea          #+#    #+#             */
/*   Updated: 2016/03/07 17:18:27 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*count_line_col(int fd, t_map *map)
{
	char	*line;
	char	**split;
	int		i;

	if (get_next_line(fd, &line) == 1)
	{
		i = 0;
		split = ft_strsplit(line, ' ');
		while (split[i] != NULL)
			i++;
		map->nb_line = 1;
		map->nb_col = i;
	}
	while (get_next_line(fd, &line) == 1)
	{
		i = 0;
		split = ft_strsplit(line, ' ');
		while (split[i] != NULL)
			i++;
		map->nb_line = map->nb_line + 1;
		if (i != map->nb_col)
			ft_exit("Fichier non conforme");
	}
	return (map);
}

t_map	*split_tab(t_map *map, int fd)
{
	char	**split;
	char	*line;
	int		i;
	int		j;

	i = 0;
	while (get_next_line(fd, &line) == 1)
	{
		j = 0;
		map->tab[i] = (int *)malloc(sizeof(int *) * (map->nb_col));
		split = ft_strsplit(line, ' ');
		while (split[j] != NULL)
		{
			map->tab[i][j] = ft_atoi(split[j]);
			j++;
		}
		i++;
	}
	return (map);
}

void	parsing(char *argv, t_map *map)
{
	int		fd;

	map->nb_line = 0;
	map->nb_col = 0;
	if ((fd = open(argv, O_RDONLY)) == -1)
		ft_exit("erreur de lecture");
	map = count_line_col(fd, map);
	map->tab = (int **)malloc(sizeof(int *) * (map->nb_line));
	map->tab[map->nb_line] = NULL;
	close(fd);
	fd = open(argv, O_RDONLY);
	map = split_tab(map, fd);
	close(fd);
	map = get_altitude(map);
}

t_map	*get_altitude(t_map *map)
{
	int		i;
	int		zmin;
	int		zmax;
	int		j;

	i = 0;
	zmin = map->tab[0][0];
	zmax = map->tab[0][0];
	while (i < map->nb_line)
	{
		j = 0;
		while (j < map->nb_col)
		{
			if (map->tab[i][j] <= zmin)
				zmin = map->tab[i][j];
			if (map->tab[i][j] >= zmax)
				zmax = map->tab[i][j];
			j++;
		}
		i++;
	}
	map->zmin = zmin;
	map->zmax = zmax;
	return (map);
}
