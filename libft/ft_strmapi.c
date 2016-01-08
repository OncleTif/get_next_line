/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 10:25:10 by tmanet            #+#    #+#             */
/*   Updated: 2015/12/07 10:48:25 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
			ptr[i] = f(i, s[i]);
			i++;
		}
	}
	return (ptr);
}
