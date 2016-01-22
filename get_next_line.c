/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 10:47:35 by tmanet            #+#    #+#             */
/*   Updated: 2016/01/22 10:43:05 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_file_mem	*ft_newfmem(int const fd, t_file_mem **fmem)
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

static int			ft_read_buf(t_file_mem *cfmem)
{
	t_list	*elem;
	char	buf[BUFF_SIZE + 1];
	int		ret;
	int		i;

	i = 0;
	if (!cfmem->lst)
		cfmem->lst = ft_lstnew(NULL, 0);
	elem = cfmem->lst;
	while (elem->next)
		elem = elem->next;
	ret = read(cfmem->fd, buf, BUFF_SIZE);
	if (ret == -1)
		return (ret);
	elem->next = ft_lstnew(buf, ret);
	while (i < ret)
	{
		if (buf[i] == '\n')
			return (1);
		i++;
	}
	if (!ret)
		cfmem->eof = 1;
	return (!ret);
}

static size_t		ft_line_size(t_file_mem *cfmem, int *found)
{
	size_t	i;
	size_t	size;
	char	*str;
	t_list	*lst;

	lst = cfmem->lst;
	size = 0;
	i = 0;
	while (lst)
	{
		str = (char*)lst->content;
		while (i < lst->content_size)
		{
			if (str[i] == '\n')
			{
				*found = 1;
				return (size);
			}
			i++;
			size++;
		}
		lst = lst->next;
		i = 0;
	}
	return (size * cfmem->eof);
}

static int			ft_ret_line(char **line, t_file_mem *cf, size_t size)
{
	size_t	j;
	t_list	*next;

	j = 0;
	*line = ft_strnew(size);
	if (!*line)
		return (-1);
	while ((size - j || cf->lst->next) && cf->lst->content_size <= size - j)
	{
		ft_memcpy(*line + j, cf->lst->content, cf->lst->content_size);
		j = j + cf->lst->content_size;
		free(cf->lst->content);
		next = cf->lst->next;
		free(cf->lst);
		cf->lst = next;
	}
	ft_memcpy(*line + j, cf->lst->content, size - j);
	if (!(next = ft_lstnew(cf->lst->content + (size - j) + !cf->eof,
					cf->lst->content_size - (size - j) - !cf->eof)))
		next = cf->lst->next;
	free(cf->lst->content);
	free(cf->lst);
	cf->lst = next;
	return ((size) || !(cf->eof) || (cf->eof = 0));
}

int					get_next_line(int const fd, char **line)
{
	static t_file_mem	*fmem;
	t_file_mem			*cfmem;
	int					found;
	size_t				size;

	found = 0;
	if (!line || BUFF_SIZE < 1)
		return (-1);
	cfmem = fmem;
	while (cfmem && cfmem->fd != fd)
		cfmem = cfmem->next;
	if (!cfmem)
		if (!(cfmem = ft_newfmem(fd, &fmem)))
			return (-1);
	size = ft_line_size(cfmem, &found);
	while (!found && !cfmem->eof)
	{
		found = ft_read_buf(cfmem);
		if (found == -1)
			return (-1);
	}
	size = ft_line_size(cfmem, &found);
	return (ft_ret_line(line, cfmem, size));
}
