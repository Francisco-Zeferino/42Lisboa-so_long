SRC = main.c map_checker.c error_handling.c list_utils.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

NAME = so_long

CC = cc

CFLAGS = -Wall -Werror -Wextra

OBJ :=$(SRC:.c=.o)

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
