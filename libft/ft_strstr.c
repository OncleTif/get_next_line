/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 16:17:25 by tmanet            #+#    #+#             */
/*   Updated: 2015/12/03 14:47:18 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[i])
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
