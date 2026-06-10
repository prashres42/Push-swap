NAME	= push_swap.a
CC	= cc
CFLAGS	= -Wall -Werror -Wextra
SRCS =	check_flags.c swap.c push.c reverse_r.c rotate.c\
		simple_selection.c main.c\

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c $(NAME)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 
