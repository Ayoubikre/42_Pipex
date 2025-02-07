CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = a.c
OBJ = $(SRC:.c=.o)

libft_DIR = ./function/42_Libft
printf_DIR = ./function/42_Printf
gnl_DIR = ./function/42_Get-next-line

libft = $(libft_DIR)/libft.a
printf = $(printf_DIR)/libftprintf.a
gnl = $(libft_gnl_DIRDIR)/libftgnl.a

NAME = a

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(libft_DIR)
	make -C $(printf_DIR)
	make -C $(gnl_DIR)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(libft) $(printf) $(gnl)

%.o: %.c a.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C $(libft_DIR) clean
	make -C $(printf_DIR) clean
	make -C $(gnl_DIR) clean
	rm -f $(OBJ)

fclean: clean
	make -C $(libft_DIR) fclean
	make -C $(printf_DIR) fclean
	make -C $(gnl_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
