CC = cc
CFLAGS = -Wall -Wextra -Werror
CFLAGS = -Wall 

SRC1 = get_next_line_utils_bonus.c get_next_line_bonus.c
OBJ = $(SRC1:.c=.o)

NAME = libftgnl.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c get_next_line_bonus.h
	$(CC)  -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all
