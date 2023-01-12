NAME = push_swap

CFLAGS = -Wall -Werror -Wextra 

SRCS = check_inputs.c execute.c ft_split.c helpers.c input_check.c main.c moves.c position.c push.c \
	   quick_sort.c reverse_rotate.c rotate.c soritng.c stack.c start_stack.c swap.c 

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(SRCS)
		cc $(CFLAGS) $(SRCS) -o $(NAME)

clean :
		@rm -rf $(OBJS)

fclean : clean
		@rm -rf $(NAME)

re :	fclean all