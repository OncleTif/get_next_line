/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 12:54:48 by tmanet            #+#    #+#             */
/*   Updated: 2015/12/07 13:04:39 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;

	tmp = NULL;
	if (lst && f)
	{
		tmp = f(lst);
		if (!tmp)
			return (NULL);
		if (lst->next)
			tmp->next = ft_lstmap(lst->next, f);
	}
	return (tmp);
}
