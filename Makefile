SRC = $(wildcard *.c)

NAME = so_long

CC = cc

CFLAGS = -Wall -Werror -Wextra -g

OBJ :=$(SRC:.c=.o)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib \
	-Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -I/usr/include \
	-Imlx_linux -O3 -c $< -o $@
