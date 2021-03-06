/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 10:54:38 by tmanet            #+#    #+#             */
/*   Updated: 2016/01/08 12:10:03 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# define BUFF_SIZE 4

int						get_next_line(int const fd, char **line);

typedef struct			s_file_mem
{
	int					fd;
	int					eof;
	t_list				*lst;
	struct s_file_mem	*next;
}						t_file_mem;

#endif
