/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 10:54:38 by tmanet            #+#    #+#             */
/*   Updated: 2016/01/07 13:04:30 by tmanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# define BUFF_SIZE 4

int						get_next_line(int const fd, char **line);
void					ft_printlst(t_list *lst);

typedef struct			s_file_mem
{
	int					fd;
	int					eof;
	t_list				*lst;
	size_t				offset;
	struct s_file_mem	*next;
}						t_file_mem;

#endif
