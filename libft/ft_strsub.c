/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 10:31:27 by tmanet            #+#    #+#             */
/*   Updated: 2015/12/10 10:23:53 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ptr;

	ptr = NULL;
	if (s)
	{
		i = 0;
		ptr = ft_strnew(len);
		if (!ptr)
			return (NULL);
		while (s[start + i] && i < len)
		{
			ptr[i] = s[start + i];
			i++;
		}
	}
	return (ptr);
}
