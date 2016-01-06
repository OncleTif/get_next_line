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

	argc++;
	fd = open(argv[1], O_RDWR);
ret = get_next_line(fd, &str);
printf("1er appel la chaine est : %s et le retour est %d\n", str, ret);
ret = get_next_line(fd, &str);
printf("2eme appel la chaine est : %s et le retour est %d\n", str, ret);
ret = get_next_line(fd, &str);
printf("3eme appel la chaine est : %s et le retour est %d\n", str, ret);
ret = get_next_line(fd, &str);
printf("4eme appel la chaine est : %s et le retour est %d\n", str, ret);

	return 0;
}
