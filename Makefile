# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lminta <lminta@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/02 20:58:32 by lminta            #+#    #+#              #
#    Updated: 2019/11/10 16:25:30 by lminta           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

INC = inc

LIBS = lib

FLAGS = -Wall -Werror -Wextra -c -Ofast

FLAGS2 = -lftmlx -lcomplex

OBJ = src/fractol.o src/g_print.o src/mandelbrot.o src/keys.o src/print_text.o \
src/mandelmods.o src/juliamods.o src/julia.o src/newtonmods.o src/newton.o

all: lib $(NAME)

$(NAME): $(OBJ)
	make -C mlx_graph
	make -C minilibx_macos
	gcc $(OBJ) -L $(LIBS) $(FLAGS2) \
	-I minilibx_macos -L minilibx_macos -lmlx -framework OpenGL \
	-framework Appkit -o $(NAME)

$(OBJ): %.o: %.c
	gcc $(FLAGS) -I$(INC) $< -o $@

clean:
	make -C mlx_graph fclean
	make -C minilibx_macos clean
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

lib:
	mkdir lib

re: fclean all
