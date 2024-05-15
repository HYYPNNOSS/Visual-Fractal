# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hel-hich <hel-hich@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/02 20:43:06 by hel-hich          #+#    #+#              #
#    Updated: 2022/07/19 21:09:06 by hel-hich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror
MLX_CMD = -lmlx -framework OpenGL -framework AppKit
NAME = fractol

SRC = ./shared/fractol_utils.c\
		./shared/hooks.c\
		./shared/julia_sets.c\
		./shared/redraw.c\
		./src/julia.c\
		./src/main.c\
		./src/mandelbrot.c\
		./src/burningShip.c

OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

OBJ_DIR = ./obj

INC = include/fractol.h

all : $(NAME)

$(NAME) : $(OBJ)
		$(CC) $(CFLAGS) $(MLX_CMD) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o : %.c  $(INC)
		@mkdir -p $(dir $@)
		$(CC) $(CFLAGS) -c $< -o $@

clean :
		@rm -rf $(OBJ_DIR)

fclean : clean
		@rm -rf $(NAME)

re : fclean $(NAME)
