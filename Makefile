NAME = push_swap
CFILES = check.c execute.c input_check.c main.c moves.c position.c push.c quick_sort.c\
		 reverse_rotate.c rotate.c soritng.c stack.c start_stack.c swap.c helpers.c ft_split.c
OBJECTS = $(CFILES:.c=.o)
CFLAGS = -Wall -Wextra -Werror 
CC = gcc
#generating the compile files 
$(NAME): $(OBJECTS)
	@echo "------CREATING-----" $(NAME) 	
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)
	
all: $(NAME) 

# Generating Object files 
%.o: %.c
	@echo " ---- Creating" [ $@ ] " -----"
	$(CC) $(CFLAGS) -c $< -o $@ 
	
clean: 
	rm -rf $(NAME) $(OBJECTS) $(BONUS_OJS) 
fclean: clean 
	rm -rf $(NAME)
	
re: clean all 	