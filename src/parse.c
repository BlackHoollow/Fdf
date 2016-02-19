/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 15:10:46 by nromptea          #+#    #+#             */
/*   Updated: 2016/02/19 20:03:23 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "fdf.h"

#include "libft.h"

int		main(int argc, char *argv)
{
	
}

int		**parsing(char *argv)
{
	int		**tab;
	int		fd;
	char	*line;
	int		i;
	int		len;
	char	**split;

	fd = open(argv, O_RDONLY);
	len = 0;
	i = 0;
	while (get_next_line(fd, &line) == 1)
	{
		if (ft_strlen(line) > len)
			len = ft_strlen(line);
		i++;
	}
	close(fd);
	tab = (int **)malloc(sizeof(int *) * i);
	fd = open(argv, O_RDONLY);
	i = 0;
	while (get_next_line(fd, &line) == 1)
	{
		*tab = (int *)malloc(sizeof(int) * len);
		*tab[len] = 0;
		split = ft_strsplit(line, ' ');
		*tab[i] = ft_getnbr(split[i]);
	}
}
