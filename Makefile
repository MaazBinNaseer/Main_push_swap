NAME = push_swap

CFLAGS = -Wall -Werror -Wextra -g3 #

SRCS = check_inputs.c execute.c ft_split.c helpers.c input_check.c main.c moves.c position.c push.c \
	   quick_sort.c reverse_rotate.c rotate.c soritng.c stack.c start_stack.c swap.c main_helpers.c

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
		cc $(CFLAGS) $(OBJS) -o $(NAME)

all : $(NAME)

%.o :%.c 
	cc $(CFLAGS) -c $< -o $@ 

clean :
		@rm -rf $(OBJS)

fclean : clean
		@rm -rf $(NAME)

re :	fclean all