CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = ./Mandatory/src/main.c ./Mandatory/src/initialize.c ./Mandatory/src/process.c ./Mandatory/src/execve.c ./Mandatory/src/ft_split2.c

OBJ = $(SRC:.c=.o)

libft_DIR = ./42_Libft
libft = $(libft_DIR)/libft.a

NAME = ./pipex

all: $(NAME)

$(NAME): $(OBJ) 
	make -C $(libft_DIR)
	$(CC)  $(CFLAGS) $(OBJ) -o $(NAME) $(libft)

bonus: $(NAME) fclean
	make -C ./bonus

%.o: %.c ./main.h $(libft_DIR)/libft.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C $(libft_DIR) clean
	make -C ./bonus clean
	rm -f $(OBJ)

fclean: clean
	make -C $(libft_DIR) fclean
	make -C ./bonus fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
