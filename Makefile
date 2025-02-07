CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = a
SRC = a.c
OBJ = $(SRC:.c=.o)
libft_DIR = 42_Libft

libft = $(libft_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(libft_DIR)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(libft)

%.o: %.c a.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C $(libft_DIR) clean
	rm -f $(OBJ)

fclean: clean
	make -C $(libft_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
