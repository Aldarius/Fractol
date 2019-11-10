# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lminta <lminta@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/02 20:58:32 by lminta            #+#    #+#              #
#    Updated: 2019/11/10 16:21:40 by lminta           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ../lib/libcomplex.a

INC = ../inc

FLAGS = -Wall -Werror -Wextra -c -Ofast

OBJ = c_div_diff_set.o complex.o

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

$(OBJ): %.o: %.c
	gcc $(FLAGS) -I$(INC) $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
