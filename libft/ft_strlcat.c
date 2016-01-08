/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 10:27:33 by tmanet            #+#    #+#             */
/*   Updated: 2015/12/03 17:11:35 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	dst_size;
	size_t	dst_pos;

	dst_size = ft_strlen(dst);
	if (dst_size >= n)
		return (ft_strlen(src) + n);
	dst_pos = dst_size;
	i = 0;
	while (dst_pos < n && src[i])
	{
		dst[dst_pos] = src[i];
		i++;
		dst_pos++;
	}
	if (dst_pos == n)
		dst_pos--;
	dst[dst_pos] = 0;
	return (ft_strlen(src) + dst_size);
}
