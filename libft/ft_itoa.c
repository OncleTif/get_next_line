/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 12:48:41 by tmanet            #+#    #+#             */
/*   Updated: 2015/12/10 15:40:25 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_uitoaa(unsigned int nbr, char *ptr)
{
	int				i;
	size_t			range;

	i = 0;
	range = ft_range(nbr);
	while (range)
	{
		ptr[i] = nbr / range + '0';
		nbr = nbr % range;
		range = range / 10;
		i++;
	}
}

char		*ft_itoa(int n)
{
	int				neg;
	unsigned int	nbr;
	size_t			size;
	char			*ptr;
	int				i;

	i = 0;
	neg = 1;
	if (n < 0)
		neg = -1;
	nbr = n * neg;
	size = ft_intsize(nbr);
	ptr = ft_strnew(size + (neg == -1));
	if (!ptr)
		return (NULL);
	if (neg == -1)
	{
		ptr[i] = '-';
		i++;
	}
	ft_uitoaa(nbr, ptr + i);
	return (ptr);
}
