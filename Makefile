# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmanet <tmanet@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/06 10:58:59 by tmanet            #+#    #+#              #
#    Updated: 2016/01/07 12:14:50 by tmanet           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = GNL
SRCS = main.c get_next_line.c ft_printlst.c
OBJ = $(SRCS:.c=.o)
LIB = libft/libft.a

all : $(NAME)

$(NAME) : $(LIB) $(OBJ)
	gcc -o $(NAME) $(OBJ) -I libft/includes -L libft/ -lft

$(LIB) :
	make -C libft/

%o: %.c $@
	gcc -Wall -Wextra -Werror -I libft/includes -c $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re : fclean all

cleanlib:
	make -C libft/ fclean

relib: cleanall all

cleanall: cleanlib fclean
