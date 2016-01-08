/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 16:42:07 by tmanet            #+#    #+#             */
/*   Updated: 2015/12/07 16:42:32 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_range(unsigned int nbr)
{
	int	range;

	range = 1;
	while (nbr >= 10)
	{
		range = range * 10;
		nbr = nbr / 10;
	}
	return (range);
}
