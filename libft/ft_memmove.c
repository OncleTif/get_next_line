/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 11:14:01 by tmanet            #+#    #+#             */
/*   Updated: 2015/12/02 15:33:00 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dst_char;
	char	*src_char;

	if (dst > src && dst < src + len)
	{
		dst_char = (char*)dst;
		src_char = (char*)src;
		while (len > 0)
		{
			len--;
			dst_char[len] = src_char[len];
		}
		return (dst);
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
