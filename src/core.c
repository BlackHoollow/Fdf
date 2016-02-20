/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 16:59:39 by nromptea          #+#    #+#             */
/*   Updated: 2016/02/20 18:26:41 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	int		**tab;

	argc = argc + 0;
	ft_putendl("coucou");
	tab = parsing(argv[1]);
	ft_putendl("oui");
	print_tab(tab);
	ft_putendl("wat");
	return (0);
}
