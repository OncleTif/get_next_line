/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 09:41:37 by tmanet            #+#    #+#             */
/*   Updated: 2015/12/07 16:46:13 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	buf;
	int				range;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		buf = n * -1;
	}
	else
	{
		buf = n;
	}
	range = ft_range(buf);
	while (range)
	{
		ft_putchar_fd((buf / range + '0'), fd);
		buf = buf % range;
		range = range / 10;
	}
}
