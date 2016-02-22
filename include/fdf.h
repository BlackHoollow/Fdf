/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 15:17:20 by nromptea          #+#    #+#             */
/*   Updated: 2016/02/22 20:37:27 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"

/*
** parse.c
*/

void	count_line_col(int fd, int *nb_col, int *nb_line);
int		*fill_it(int nb, int *tab);
int		check(char *str);
int		**split_tab(int **tab, int nb_col, int fd);
int		**parsing(char *argv);

/*
** core.c
*/

void	ft_exit(char *str);
void	print_tab(int **tab, int nb_col, int nb_line);
int		main(int argc, char **argv);

#endif
