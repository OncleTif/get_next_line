/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 09:31:29 by tmanet            #+#    #+#             */
/*   Updated: 2015/12/03 14:50:01 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[i] && i < n)
	{
		if (!s2[j])
			return ((char*)&s1[i - j]);
		if (s1[i] == s2[j])
			j++;
		else
		{
			i = i - j;
			j = 0;
		}
		i++;
	}
	if (!s2[j])
		return ((char*)&s1[i - j]);
	return (NULL);
}
