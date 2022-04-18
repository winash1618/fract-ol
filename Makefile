# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkaruvan <mkaruvan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/17 15:13:52 by mkaruvan          #+#    #+#              #
#    Updated: 2022/04/18 08:30:41 by mkaruvan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fractol

LIBX_DIR	=	minilibx

LIBX		=	libmlx.a

INC_DIR		=	includes

FRAMEWORK	=	-L $(LIBX_DIR) -lmlx -framework OpenGL -framework AppKit

SRC_DIR		=	srcs

SRCS		=	render_julia.c fractol.c events.c utils.c render_mandelbrot.c \
				ft_atof.c

OBJS		=	$(addprefix $(SRC_DIR)/, $(SRCS:%c=%o))

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror -Ofast

$(SRC_DIR)/%.o : $(SRC_DIR)/%.c
				$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

all : $(NAME)

bonus : re

$(NAME) : $(OBJS) $(LIBX)
	@$(CC) $(CFLAGS) $(OBJS) $(FRAMEWORK) -o $(NAME)

$(LIBX):
	@make -C $(LIBX_DIR)
	
clean:
	@make -C $(LIBX_DIR) clean
	@rm -f $(SRC_DIR)/*.o
	
fclean: clean
	@rm -f $(NAME)
	
re:	fclean all
