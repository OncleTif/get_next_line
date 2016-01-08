/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 10:46:57 by tmanet            #+#    #+#             */
/*   Updated: 2015/12/07 10:51:14 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_size;
	size_t	s2_size;
	char	*ptr;

	ptr = NULL;
	if (s1 && s2)
	{
		s1_size = ft_strlen(s1);
		s2_size = ft_strlen(s2);
		ptr = ft_strnew(s1_size + s2_size + 1);
		if (!ptr)
			return (NULL);
		ft_strcpy(ptr, s1);
		ft_strcpy(ptr + s1_size, s2);
	}
	return (ptr);
}
