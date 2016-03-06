/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/06 20:17:24 by nromptea          #+#    #+#             */
/*   Updated: 2016/03/06 20:17:38 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		my_key_func(int keycode, void *param)
{
	ft_putstr("Key event : ");
	ft_putnbr(keycode);
	ft_putchar('\n');
	if (keycode == 53)
		ft_exit("quit");
	if (keycode == 37)
	{
		put_thing(param);
	}
	return (0);
}
