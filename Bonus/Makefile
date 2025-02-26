CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = ./src/main.c ./src/initialize.c ./src/process.c ./src/execve.c ./src/ft_split2.c ./src/herdoc.c

OBJ = $(SRC:.c=.o)

libft_DIR = ../42_Libft
libft = $(libft_DIR)/libft.a

NAME = ../pipex

all: $(NAME)

$(NAME): $(OBJ) 
	make -C $(libft_DIR)
	$(CC)  $(CFLAGS) $(OBJ) -o $(NAME) $(libft)

%.o: %.c ./main.h $(libft_DIR)/libft.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C $(libft_DIR) clean
	rm -f $(OBJ)

fclean: clean
	make -C $(libft_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
