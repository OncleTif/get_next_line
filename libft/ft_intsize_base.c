/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intsize_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 10:39:46 by tmanet            #+#    #+#             */
/*   Updated: 2015/12/10 10:46:39 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_intsize_base(unsigned int nbr, unsigned int base)
{
	size_t	i;

	i = 1;
	while (nbr >= base)
	{
		nbr = nbr / base;
		i++;
	}
	return (i);
}
