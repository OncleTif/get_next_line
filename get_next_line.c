/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 10:47:35 by tmanet            #+#    #+#             */
/*   Updated: 2015/12/28 16:26:16 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_file_mem		*ft_newfmem(int const fd, t_file_mem *fmem)
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

static int				ft_read_buf(t_list *lst, int fd)
{
	t_list	*elem;
	char	buf[BUFF_SIZE];
	size_t	ret;
	char	*str;

	elem = lst;
	while (elem->next)
		elem = elem->next;
	ret = read(fd, buf, BUFF_SIZE);
	if (ret <= 0)
		return (ret);
	str = ft_strnew(ret);
	elem->next = ft_lstnew(ft_memcpy(str, buf, ret), ret);
	return (ret);
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

static int			ft_ret_line(char **line, t_file_mem *cfmem, size_t size)
{
	int	i;

	i = 0;

	return (0);
}

int					get_next_line(int const fd, char **line)
{
	static t_file_mem	*fmem;
	t_file_mem			*cfmem;
	int					comp;
	int					read_ret;
	size_t				size;

	comp = 0;
	cfmem = fmem;
	while (cfmem && cfmem->fd != fd)
		cfmem = cfmem->next;
	if (!cfmem)
		if (!(cfmem = ft_newfmem(fd, fmem)))
			return (-1);
	while (!(size = ft_line_size(cfmem->lst, comp)))
	{
		read_ret = ft_read_buf(cfmem->lst, fd);
		if (read_ret < 0)
			return (-1);
		else if (read_ret == 0)
			comp = 1;
	}
	*line = ft_strnew(size);
	return (ft_ret_line(line, cfmem, size));
}
