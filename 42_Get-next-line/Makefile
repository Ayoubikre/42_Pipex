CC = cc
CFLAGS = -Wall -Wextra 
SRCS1 =  get_next_line_utils.c  get_next_line.c  main.c
# SRCS1 =  get_next_line_utils_bonus.c  get_next_line_bonus.c  main.c
OBJS = $(SRCS1:.c=.o)

NAME = a

all: $(NAME) c

$(NAME): $(OBJS) 
	$(CC) $(CFLAGS)  $(OBJS) -o $(NAME)
	./$(NAME)

c:
	@rm -rf $(OBJS) 

fc: c
	@rm -rf $(NAME) 

re: fc all

