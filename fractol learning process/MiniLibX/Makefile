NAME		=	9-print_hexagons
LIBX_DIR	=	minilibx
LIBX		=	libmlx.a
FRAMEWORK	=	-L $(LIBX_DIR) -lmlx -framework OpenGL -framework AppKit
SRCS = 9-print_hexagons.c
OBJS		=	$(SRCS:%c=%o)
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -Ofast

%.o : %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(FRAMEWORK) -o $(NAME)
	@rm -f 9-print_hexagons.o

all : $(NAME)