/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 10:40:43 by tmanet            #+#    #+#             */
/*   Updated: 2015/12/10 15:42:01 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_uitoaa_base(unsigned int nbr, char *ptr, unsigned int base)
{
	int				i;
	size_t			range;
	int				digit;

	i = 0;
	range = ft_range_base(nbr, base);
	while (range)
	{
		digit = nbr / range;
		if (digit < 10)
			ptr[i] = digit + '0';
		else
			ptr[i] = digit + 'A' - 10;
		nbr = nbr % range;
		range = range / base;
		i++;
	}
}

char		*ft_itoa_base(int n, unsigned int base)
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
	size = ft_intsize_base(nbr, base);
	ptr = ft_strnew(size + (neg == -1));
	if (!ptr)
		return (NULL);
	if (neg == -1)
	{
		ptr[i] = '-';
		i++;
	}
	ft_uitoaa_base(nbr, ptr + i, base);
	return (ptr);
}
