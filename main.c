/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 10:51:40 by tmanet            #+#    #+#             */
/*   Updated: 2016/01/06 10:58:27 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(int argc, char **argv)
{
	char	*str;
	int		fd;
	int		ret;
	int		i;

	i = 1;
	argc++;
	fd = open(argv[1], O_RDWR);
	while ((ret = get_next_line(fd, &str)))
	{
		printf("appel n %d la chaine est : %s et le retour est %d\n", i, str, ret);
		i++;
	}
	printf("appel n %d la chaine est : %s et le retour est %d\n", i, str, ret);
	return 0;
}
