/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 10:47:35 by tmanet            #+#    #+#             */
/*   Updated: 2015/12/28 15:21:00 by tmanet           ###   ########.fr       */
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

static size_t			ft_line_size(t_list *lst, int complete)
{
	size_t	size;
	size_t	i;
	char	*str;

	size = 0;
	while (!complete && lst)
	{
		i = 0;
		str = (char*)lst->content;
		while (!complete && i < lst->content_size)
		{
			if (str[i] == '\n')
				complete = 1;
			i++;
			size++;
		}
		lst = lst->next;
	}
	return (size * complete);
}

int					get_next_line(int const fd, char **line)
{
	static t_file_mem	*fmem;
	t_file_mem			*cfmem;
	char				buf[BUFF_SIZE + 1];
	int					comp;
	size_t				size;

	cfmem = fmem;
	comp = 0;
	while (cfmem && cfmem->fd != fd)
		cfmem = cfmem->next;
	if (!cfmem)
		if (!(cfmem = ft_newfmem(fd, fmem)))
			return (-1);
	while (!(size = ft_line_size(cfmem->lst, comp)))
	{
		size++;
	}

	return (0);
}
