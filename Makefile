# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lcorinna <lcorinna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/08 15:13:25 by lcorinna          #+#    #+#              #
#    Updated: 2021/12/14 20:02:43 by lcorinna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBF = libft.a # i here

PRINTF = to_the_hexadecimal_system.c to_display_on_the_screen.c ft_printf.c

OBJ_FILES = $(PRINTF:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	ar rcs $(NAME) $?

%.o: %.c libftprintf.h Makefile
	gcc -Wall -Wextra -Werror -c $< -o $@

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re