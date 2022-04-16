NAME		=	fractol
LIBX_DIR	=	minilibx
LIBX		=	libmlx.a
INC_DIR		=	includes
FRAMEWORK	=	-L $(LIBX_DIR) -lmlx -framework OpenGL -framework AppKit
SRC_DIR		=	srcs
SRCS		=	render_julia.c fractol.c events.c utils.c
OBJS		=	$(addprefix $(SRC_DIR)/, $(SRCS:%c=%o))
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -Ofast

 $(SRC_DIR)/%.o : $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJS) $(LIBX)
	@$(CC) $(CFLAGS) $(OBJS) $(FRAMEWORK) -o $(NAME)
	@rm -f 4-julia_set_full.o

$(LIBX):
	@make -C $(LIBX_DIR)
clean:
	@make -C $(LIBX_DIR) clean
	@rm -f $(SRC_DIR)/*.o
fclean: clean
	@rm -f $(NAME)
re:	fclean all
