CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = ./Mandatory/src/main.c ./Mandatory/src/initialize.c ./Mandatory/src/process.c ./Mandatory/src/execve.c ./Mandatory/src/ft_split2.c

OBJ = $(SRC:.c=.o)

libft_DIR = ./42_Libft
libft = $(libft_DIR)/libft.a

M_check = /tmp/.M_check
B_check = /tmp/.B_check

NAME = ./pipex

all: $(NAME)

$(NAME): $(OBJ)  $(M_check)
	make -C $(libft_DIR)
	$(CC)  $(CFLAGS) $(OBJ) -o $(NAME) $(libft)

$(M_check):
	touch $(M_check)
	rm -rf $(B_check)

bonus:
	make -C ./Bonus

%.o: %.c ./Mandatory/main.h $(libft_DIR)/libft.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C $(libft_DIR) clean
	make -C ./bonus clean
	rm -f $(OBJ)

fclean: clean
	make -C ./bonus fclean
	make -C $(libft_DIR) fclean
	rm -f $(M_check)
	rm -f $(NAME)


re: fclean all

.PHONY: all bonus clean fclean re
