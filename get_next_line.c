/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 10:47:35 by tmanet            #+#    #+#             */
/*   Updated: 2015/12/28 14:39:29 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_file_mem	*ft_newfmem(int const fd, t_file_mem *fmem)
{
	t_file_mem	*cfmem;
	t_file_mem	*last_fmem;

	cfmem = (t_file_mem*)ft_memalloc(sizeof(t_file_mem));
	if (cfmem)
		cfmem->fd = fd;
	if (!fmem)
		fmem = cfmem;
	else
	{
		last_fmem = fmem;
		while (last_fmem->next)
			last_fmem = last_fmem->next;
		last_fmem->next = cfmem;
	}
	return (cfmem);
}

static int			ft_line_size(t_file_mem *cfmem)
{
	return (0);
}

int					get_next_line(int const fd, char **line)
{
	static t_file_mem	*fmem;
	t_file_mem			*cfmem;
	char				buf[BUFF_SIZE + 1];
	int					line_read;
	size_t				size;

	cfmem = fmem;
	line_read = 0;
	while (cfmem && cfmem->fd != fd)
		cfmem = cfmem->next;
	if (!cfmem)
		if (!(cfmem = ft_newfmem(fd, fmem)))
			return (-1);
	while (!(size = ft_line_size(cfmem)))
	{
		size++;
	}
	return (0);
}
