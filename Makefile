# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/08 15:13:25 by lcorinna          #+#    #+#              #
#    Updated: 2021/12/25 20:18:34 by lcorinna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

PRINTF = to_the_hexadecimal_system.c to_display_on_the_screen.c ft_printf.c

OBJ_FILES = $(PRINTF:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	cd libft && make
	cp libft/libft.a $(NAME)
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

.PHONY: all clean fclean re
