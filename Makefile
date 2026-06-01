NAME	= push_swap.a
CC	= cc
CFLAGS	= -Wall -Werror -Wextra
SRCS =  \

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
