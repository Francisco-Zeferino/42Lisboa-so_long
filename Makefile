SRC = src/main.c src/map_checker.c src/error_handling.c src/init_mlx.c src/draw_sprites.c src/store_map.c src/flood_fill.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c Libft/ft_split.c Libft/ft_strrchr.c Libft/ft_strncmp.c Libft/ft_calloc.c

NAME = so_long

CC = cc

CFLAGS = -Wall -Werror -Wextra -g

OBJ :=$(SRC:.c=.o)

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib \
	-Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include \
	-Imlx_linux -O3 -c $< -o $@

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re
