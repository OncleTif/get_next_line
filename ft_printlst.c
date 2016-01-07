/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 11:50:59 by tmanet            #+#    #+#             */
/*   Updated: 2016/01/07 12:15:59 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_printlst(t_list	*lst)
{
	char	*str;
	if (!lst)
		ft_putendl("not a lst");
	else
	{
		ft_putstr("lst content size : ");
		ft_putnbrendl(lst->content_size);
		ft_putstr("lst content size : ");
		ft_putnstr(lst->content, lst->content_size);
		ft_putchar('\n');
	}
}
