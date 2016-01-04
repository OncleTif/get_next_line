/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 10:47:35 by tmanet            #+#    #+#             */
/*   Updated: 2016/01/04 15:21:22 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_file_mem		*ft_newfmem(int const fd, t_file_mem *fmem)
{
	t_file_mem	*cfmem;
	t_file_mem	*last_fmem;

	cfmem = (t_file_mem*)ft_memalloc(sizeof(t_file_mem));
	if (cfmem)
	{
		cfmem->fd = fd;
		cfmem->lst = ft_lstnew(NULL, 0);
	}
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

static size_t			ft_line_size(t_list *lst, int force, size_t offset)
{
	size_t	size;
	size_t	i;
	char	*str;

	size = 0;
	i = offset;
	while (lst)
	{
		str = (char*)lst->content;
		while (i < lst->content_size)
		{
			if (str[i] == '\n')
				return (size);
			i++;
			size++;
		}
		lst = lst->next;
		i = 0;
	}
	return (size * force);
}

static int				ft_ret_line(char **line, t_file_mem *cfmem, size_t size)
{
	size_t	j;
	size_t	k;
	t_list	*next;
	char	*ret;

	j = 0;
	ret = ft_strnew(size);
	if (!ret)
		return (-1);
	ft_putstr("ret alloue, taille :");
ft_putnbr(size + 1);
	ft_print_lst(cfmem->lst);
	ft_putendl("liste imprimee");
	while (j < size)
	{
		k = cfmem->lst->content_size - cfmem->offset;
		if (k > size - j)
			k = size - j;
		ft_memcpy(ret + j, cfmem->lst->content + cfmem->offset, k);
ft_putstr("offset de debut d'ecriture : ");
ft_putnbr(j);
ft_putchar('\n');
ft_putstr("offset de debut de lecture : ");
ft_putnbr(cfmem->offset);
ft_putchar('\n');
ft_putstr("nombre de caracteres ecrits : ");
ft_putnbr(k);
ft_putchar('\n');
		ft_putendl(ret);
		j = j + k;
		cfmem->offset = 0;
		if (j < size)
		{
			next = cfmem->lst->next;
			free(cfmem->lst->content);
			free(cfmem->lst);
			cfmem->lst = next;
		}
	}
	ft_putstr(ret);
	ft_putendl("set de line");
	*line = ret;
	cfmem->offset = k;
	return (0);
}

int						get_next_line(int const fd, char **line)
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
	ft_putnbr(cfmem->fd);
	ft_putendl("cfmem OK");
	while (!(size = ft_line_size(cfmem->lst, comp, cfmem->offset)))
	{
		ft_putnbr(size);
		ft_putchar('\n');
		ft_putendl("av read");
		read_ret = ft_read_buf(cfmem->lst, fd);
		ft_putendl("ap read");
		if (read_ret < 0)
			return (-1);
		else if (read_ret == 0)
			comp = 1;
	}
	ft_putnbr(size);
	ft_putchar('\n');
	return (ft_ret_line(line, cfmem, size));
}
