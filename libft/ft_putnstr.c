/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 12:04:17 by tmanet            #+#    #+#             */
/*   Updated: 2016/01/07 12:08:29 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnstr(void const *mem, size_t size)
{
	size_t	i;
	char	*str;

	str = (char*)mem;
	i = 0;
	while (i < size && str[i] != 0)
	{
		ft_putchar(str[i]);
		i++;
	}
}
