CC = cc
CFLAGS = -Wall -Wextra

SRC = t.c
# SRC = ./M/main.c ./M/outils.c
# BONUS = ./B/main_bonus.c ./B/outils_bonus.c

OBJ = $(SRC:.c=.o)
# B_OBJ = $(BONUS:.c=.o)

libft_DIR = ./42_Libft
libft = $(libft_DIR)/libft.a

NAME = pipex

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(libft_DIR)
	$(CC)  $(CFLAGS) $(OBJ) -o $(NAME) $(libft)

# bonus: $(B_OBJ)
# 	make -C $(libft_DIR)
# 	$(CC) $(CFLAGS) $(B_OBJ) -o $(NAME) $(libft)

%.o: %.c t.h $(libft_DIR)/libft.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C $(libft_DIR) clean
	rm -f $(OBJ)

fclean: clean
	make -C $(libft_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
