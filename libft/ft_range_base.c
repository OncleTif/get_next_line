/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 10:25:32 by tmanet            #+#    #+#             */
/*   Updated: 2015/12/10 10:44:43 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_range_base(unsigned int nbr, unsigned int base)
{
	int range;

	range = 1;
	while (nbr >= (base))
	{
		range = range * base;
		nbr = nbr / base;
	}
	return (range);
}
