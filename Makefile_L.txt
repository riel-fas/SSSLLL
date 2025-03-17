NAME	= so_long
CC		= cc
CFLAGS	= -Wextra -Wall -Werror -fsanitize=address

# Paths for MLX42
LIBMLX	= /home/riad/MLX42
MLX_INCLUDE	= $(LIBMLX)/include/MLX42
MLX_LIB	= $(LIBMLX)/build/libmlx42.a

# Paths for GLFW
GLFW_INCLUDE = /home/linuxbrew/.linuxbrew/include
GLFW_LIB = /home/linuxbrew/.linuxbrew/lib

# Include paths
HEADERS	= -I ./include -I $(MLX_INCLUDE) -I $(GLFW_INCLUDE)

LIBFT	= libft/libft.a

# Libraries
LIBS = $(MLX_LIB) -L $(GLFW_LIB) -lglfw -ldl -pthread -lm -fsanitize=address

# Source files
SRCS	=	so_long_src/main.c \
            so_long_src/map.c \
            so_long_src/player_movement.c \
            so_long_src/colision.c \
            libft/get_next_line/get_next_line.c \
            libft/get_next_line/get_next_line_utils.c

OBJS	= ${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
		$(CC) $(OBJS) $(LIBFT) $(LIBS) -o $(NAME) $(CFLAGS)

$(LIBFT) :
		make -C libft

%.o: %.c
		$(CC) $(CFLAGS) $(HEADERS) -o $@ -c $<

clean:
		rm -rf $(OBJS)
		make clean -C libft

fclean: clean
		rm -rf $(NAME)
		make fclean -C libft

re: clean all

.PHONY: all clean fclean re
