# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lminta <lminta@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/02 20:58:32 by lminta            #+#    #+#              #
#    Updated: 2019/11/10 16:21:26 by lminta           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ../lib/libftmlx.a

INC = ../inc

FLAGS = -Wall -Werror -Wextra -c -Ofast

OBJ = global_fill1.o global_fill2.o help_fun.o init.o colors.o

all: $(NAME)

$(NAME): $(OBJ)
	make -C ../complex
	ar rc $(NAME) $(OBJ) ../lib/libcomplex.a

$(OBJ): %.o: %.c
	gcc $(FLAGS) -I$(INC) $< -o $@

clean:
	make -C ../complex fclean
	rm -f $(OBJ)

fclean: clean
	make -C ../complex fclean
	rm -f $(NAME)

re: fclean all
