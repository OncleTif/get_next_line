/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 11:53:30 by tmanet            #+#    #+#             */
/*   Updated: 2015/12/03 17:30:40 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*src_char;
	unsigned char	*dst_char;
	unsigned char	pattern;

	i = 0;
	src_char = (unsigned char*)src;
	dst_char = (unsigned char*)dst;
	pattern = (unsigned char)c;
	while (i < n && src_char[i] != pattern)
	{
		dst_char[i] = src_char[i];
		i++;
	}
	if (n == i)
		return (NULL);
	if (src_char[i] == pattern)
	{
		dst_char[i] = src_char[i];
		return (dst_char + i + 1);
	}
	return (NULL);
}
