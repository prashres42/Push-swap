NAME = push_swap
CC = cc
CFLAGS = -g -Wall -Wextra -Werror

LIBFT_DIR = LIBFT/
LIBFT = $(LIBFT_DIR)libft.a


SRC	= 	bench_utils.c disorder.c error_free.c flags_utils.c push_swap.c parse_utils.c stack_utils.c\
		parse_error.c complex_radix.c implement_algo.c medium_chunk.c push.c reverse_r.c\
		rotate.c swap.c simple_selection.c stack_utils2.c sort_upto5.c ft_dprintf.c

OBJ	= $(SRC:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT) 
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME) -lm

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	
re: fclean all

.PHONY: all clean fclean re
