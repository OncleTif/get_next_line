/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 15:35:04 by tmanet            #+#    #+#             */
/*   Updated: 2015/12/03 16:51:34 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s_char;
	unsigned char	pattern;

	s_char = (unsigned char*)s;
	i = 0;
	pattern = (unsigned char)c;
	if (n == 0)
		return (NULL);
	n--;
	while (s_char[i] != pattern && i < n)
		i++;
	if (s_char[i] == pattern)
		return ((void*)(s + i));
	return (NULL);
}
