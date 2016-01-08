/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 15:57:38 by tmanet            #+#    #+#             */
/*   Updated: 2015/12/03 15:00:37 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char const *s, int c)
{
	int	i;

	i = (int)(ft_strlen(s) + 1);
	while (i > 0)
	{
		i--;
		if (s[i] == (char)c)
			return ((char*)&s[i]);
	}
	return (NULL);
}
