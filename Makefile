# CC = cc
# # CFLAGS = -g -fsanitize=address  -Wall -Wextra -Werror
# CFLAGS = -Wall -Wextra -Werror

# SRC = ./Mandatory/src/main.c ./Mandatory/src/initialize.c ./Mandatory/src/process.c ./Mandatory/src/execve.c ./Mandatory/src/ft_split2.c
# # SRC = ./Bonus/src/main.c ./Bonus/src/initialize.c ./Bonus/src/process.c ./Bonus/src/execve.c ./Bonus/src/ft_split2.c

# OBJ = $(SRC:.c=.o)

# libft_DIR = ./42_Libft
# libft = $(libft_DIR)/libft.a

# # NAME = ../pipex
# NAME = pipex

# all: $(NAME)

# $(NAME): $(OBJ) 
# #	make -C $(libft_DIR)
# 	$(CC)  $(CFLAGS) $(OBJ) -o $(NAME) $(libft)

# %.o: %.c ./Mandatory/main.h $(libft_DIR)/libft.h
# 	$(CC) $(CFLAGS) -c $< -o $@
	
# # %.o: %.c ./Bonus/main.h $(libft_DIR)/libft.h
# #	$(CC) $(CFLAGS) -c $< -o $@

# clean:
# #	make -C $(libft_DIR) clean
# 	rm -f $(OBJ)

# fclean: clean
# #	make -C $(libft_DIR) fclean
# 	rm -f $(NAME)

# re: fclean all

# .PHONY: all clean fclean re




all:
	Make -C ./Bonus clean
	Make -C ./Mandatory 

bonus:
	Make -C ./Mandatory clean
	Make -C ./Bonus

clean:
	Make -C ./Mandatory clean
	Make -C ./Bonus clean

fclean:
	Make -C ./Mandatory fclean
	Make -C ./Bonus fclean

re: fclean all

.PHONY: all bonus clean fclean re

