/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nromptea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 14:38:11 by nromptea          #+#    #+#             */
/*   Updated: 2016/01/26 15:24:18 by nromptea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

static int		ft_read(int fd, char *rest[fd])
{
	int		ret;
	char	*buff;
	char	*swp;
	char	*c;

	buff = ft_strnew(BUFF_SIZE);
	while (!(c = ft_strchr(rest[fd], '\n'))
			&& (ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		swp = rest[fd];
		rest[fd] = ft_strjoin(swp, buff);
		ft_strdel(&swp);
	}
	ft_strdel(&buff);
	if (ret == -1)
		return (-1);
	if (ret == 0 && !c)
		return (0);
	return (1);
}

static char		*first_line(char *cpy_buff)
{
	int		i;
	char	*line;

	i = 0;
	while (cpy_buff[i] != '\n')
		i++;
	line = ft_strsub(cpy_buff, 0, i);
	return (line);
}

int				get_next_line(int const fd, char **line)
{
	static char		*rest[1024];
	int				ret;
	char			*swp;

	if (fd < 0 || line == NULL)
		return (-1);
	if (rest[fd] == NULL)
		rest[fd] = ft_strnew(1);
	ret = ft_read(fd, &*rest);
	if (ret == -1)
		return (-1);
	if (ret == 0)
	{
		*line = rest[fd];
		rest[fd] = NULL;
		return (0);
	}
	*line = first_line(rest[fd]);
	swp = rest[fd];
	rest[fd] = ft_strdup(ft_strchr(rest[fd], '\n') + 1);
	ft_strdel(&swp);
	return (1);
}
