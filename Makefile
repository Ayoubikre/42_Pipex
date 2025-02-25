CC = cc
# CFLAGS = -g -fsanitize=address  -Wall -Wextra -Werror
CFLAGS = -Wall -Wextra -Werror
# CFLAGS = -Wall -Wextra 

SRC = ./M2/main.c ./M2/initialize.c ./M2/process.c ./M2/execve.c ./M2/ft_split2.c
# SRC = ./M2/t.c ./M2/ft_split2.c
# BONUS = ./B/main_bonus.c ./B/outils_bonus.c

OBJ = $(SRC:.c=.o)
# B_OBJ = $(BONUS:.c=.o)

libft_DIR = ./42_Libft
libft = $(libft_DIR)/libft.a

NAME = pipex

all: $(NAME)

$(NAME): $(OBJ)
#	make -C $(libft_DIR)
	$(CC)  $(CFLAGS) $(OBJ) -o $(NAME) $(libft)

# bonus: $(B_OBJ)
# 	make -C $(libft_DIR)
# 	$(CC) $(CFLAGS) $(B_OBJ) -o $(NAME) $(libft)

%.o: %.c ./M2/main.h $(libft_DIR)/libft.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
#	make -C $(libft_DIR) clean
	rm -f $(OBJ)

fclean: clean
#	make -C $(libft_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
