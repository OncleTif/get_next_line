/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 16:22:32 by tmanet            #+#    #+#             */
/*   Updated: 2015/12/04 12:15:10 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	char	*dst_end;

	dst_end = (char*)ft_memccpy(dst, src, 0, n);
	if (!dst_end)
		return (dst);
	if ((dst + n) > dst_end)
		ft_bzero((dst_end), n - (dst_end - dst));
	return (dst);
}
