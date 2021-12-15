# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/08 15:13:25 by lcorinna          #+#    #+#              #
#    Updated: 2021/12/15 18:29:24 by lcorinna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

PRINTF = to_the_hexadecimal_system.c to_display_on_the_screen.c ft_printf.c

OBJ_FILES = $(PRINTF:.c=.o)

all: $(NAME)
	cd libft && make all

$(NAME): $(OBJ_FILES)
	ar rcs $(NAME) $?

%.o: %.c ft_printf.h Makefile
	gcc -Wall -Wextra -Werror -c $< -o $@

clean:
	rm -f $(OBJ_FILES)
	cd libft && make clean

fclean: clean
	rm -rf $(NAME)
	cd libft && make fclean

re: fclean $(NAME)
	cd libft && make fclean && make

.PHONY: all clean fclean re