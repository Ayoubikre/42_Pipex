CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS1 = ft_printf.c \
			helpers/ft_putchar.c \
			helpers/ft_putnbr.c \
			helpers/ft_putstr.c \
			helpers/ft_strlen.c \
			function/ft_print_c.c \
			function/ft_print_d.c \
			function/ft_print_p.c \
			function/ft_print_s.c \
			function/ft_print_x.c \

OBJS = $(SRCS1:.c=.o)

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re