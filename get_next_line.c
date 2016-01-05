/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 10:47:35 by tmanet            #+#    #+#             */
/*   Updated: 2016/01/05 15:53:02 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_file_mem		*ft_newfmem(int const fd, t_file_mem **fmem)
{
	t_file_mem	*cfmem;
	t_file_mem	*last_fmem;

	cfmem = (t_file_mem*)ft_memalloc(sizeof(t_file_mem));
	if (cfmem)
	{
		cfmem->fd = fd;
		cfmem->lst = ft_lstnew(NULL, 0);
	}
	if (!*fmem)
		*fmem = cfmem;
	else
	{
		last_fmem = *fmem;
		while (last_fmem->next)
			last_fmem = last_fmem->next;
		last_fmem->next = cfmem;
	}
	return (cfmem);
}

static int				ft_read_buf(t_list *lst, int fd)
{
	t_list	*elem;
	char	buf[BUFF_SIZE + 1];
	size_t	ret;

	elem = lst;
	while (elem->next)
		elem = elem->next;
	ret = read(fd, buf, BUFF_SIZE);
	if (ret <= 0)
		return (ret);
	elem->next = ft_lstnew(buf, ret);
	return (ret);
}

static size_t	ft_line_size(t_list *lst, int eof, size_t offset, size_t *size)
{
	size_t	i;
	char	*str;

	*size = 0;
	i = offset;
	while (lst)
	{
		str = (char*)lst->content;
		while (i < lst->content_size)
		{
			if (str[i] == '\n')
				return (1);
			i++;
			*size = *size + 1;
		}
		lst = lst->next;
		i = 0;
	}
	return (eof);
}

static int		ft_ret_line(char **line, t_file_mem *cf, size_t size, int eof)
{
	size_t	j;
	size_t	k;
	t_list	*next;

	j = 0;
	*line = ft_strnew(size);
	if (!*line)
		return (-1);
	while (j < size)
	{
		k = cf->lst->content_size - cf->offset;
		if (k > size - j)
			k = size - j;
		ft_memcpy(*line + j, cf->lst->content + cf->offset, k);
		j = j + k;
		if (cf->lst->content_size - cf->offset == k)
		{
			next = cf->lst->next;
			free(cf->lst->content);
			free(cf->lst);
			cf->lst = next;
			cf->offset = 0;
		}
		else
			cf->offset = k % cf->lst->content_size;
	}
	cf->offset++;
	return (!eof);
}

int			get_next_line(int const fd, char **line)
{
	static t_file_mem	*fmem;
	t_file_mem			*cfmem;
	int					read_ret;
	size_t				size;

	if (!line)
		return (-1);
	cfmem = fmem;
	while (cfmem && cfmem->fd != fd)
		cfmem = cfmem->next;
	if (!cfmem)
		if (!(cfmem = ft_newfmem(fd, &fmem)))
			return (-1);

	while (!ft_line_size(cfmem->lst, cfmem->eof, cfmem->offset, &size))
	{
		read_ret = ft_read_buf(cfmem->lst, fd);
		if (read_ret < 0)
			return (-1);
		else if (read_ret == 0)
			cfmem->eof = 1;
	}
	return (ft_ret_line(line, cfmem, size, cfmem->eof));
}
