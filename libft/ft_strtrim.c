/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 11:02:05 by tmanet            #+#    #+#             */
/*   Updated: 2015/12/07 10:56:57 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*ptr;
	size_t	i;
	size_t	j;

	ptr = NULL;
	if (s)
	{
		i = 0;
		while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
			i++;
		j = ft_strlen(s) - 1;
		while (j > i && (s[j] == ' ' || s[j] == '\n' || s[j] == '\t'))
			j--;
		ptr = ft_strsub(s, i, j - i + 1);
		if (!ptr)
			return (NULL);
	}
	return (ptr);
}
