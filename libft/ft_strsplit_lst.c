/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 17:13:24 by tmanet            #+#    #+#             */
/*   Updated: 2015/12/14 11:33:22 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_strsplit_lst(char const *str, char c)
{
	t_list	*elem;
	size_t	i;
	size_t	j;
	char	*sub;

	elem = NULL;
	i = 0;
	while (str[i] && str[i] == c)
		i++;
	if (str[i])
	{
		j = i;
		while (str[j] && str[j] != c)
			j++;
		elem = ft_lstnew(str + i, j - i + 1);
		if (elem)
		{
			sub = (char*)elem->content;
			sub[j - i] = 0;
			elem->next = ft_strsplit_lst(str + j, c);
		}
	}
	return (elem);
}
