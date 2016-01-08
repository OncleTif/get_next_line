/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 10:06:46 by tmanet            #+#    #+#             */
/*   Updated: 2015/12/10 10:22:16 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*ptr;

	ptr = NULL;
	if (s && f)
	{
		i = ft_strlen(s);
		ptr = ft_strnew(i);
		if (!ptr)
			return (NULL);
		i = 0;
		while (s[i])
		{
			ptr[i] = f(s[i]);
			i++;
		}
	}
	return (ptr);
}
