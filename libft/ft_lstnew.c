/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 11:26:46 by tmanet            #+#    #+#             */
/*   Updated: 2015/12/07 12:07:10 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*tmp;

	tmp = ft_memalloc(sizeof(t_list));
	if (tmp)
	{
		tmp->content_size = 0;
		tmp->content = NULL;
		tmp->next = NULL;
		if (content)
		{
			tmp->content_size = content_size;
			tmp->content = ft_memalloc(content_size);
			if (!tmp->content)
				return (NULL);
			ft_memcpy(tmp->content, content, content_size);
		}
	}
	return (tmp);
}
