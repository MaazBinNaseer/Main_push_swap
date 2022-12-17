/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:13:15 by mbin-nas          #+#    #+#             */
/*   Updated: 2022/12/16 12:15:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stdio.h"
# include "stdlib.h"
# include "unistd.h"
# include <limits.h>

//* Creating of the stack data
typedef struct s_source_stack
{
	int						data;
	int						index;
	int						position;
	int						target;
	int						moves_a;
	int						moves_b;
	struct s_source_stack	*next_value;
}							t_source_stack;

/*--stack operation--*/
t_source_stack *get_last_position(t_source_stack *stack);
t_source_stack *get_second_last_position(t_source_stack *stack);
t_source_stack *new_stack(int data);
void add_data_to_bottom_stack(t_source_stack **stack, t_source_stack *new_stack);
int fetch_stack_size(t_source_stack *stack);
int sorted(t_source_stack *stack);
t_source_stack *fill_stack(int argc, char **argv);
void put_index_on_data(t_source_stack *stack_a, int stack_size);



/*----Finding the position----*/
int get_low_point_index(t_source_stack **stack);
void fetch_target_position(t_source_stack **stack_a, t_source_stack **stack_b);

/*---MOVES---*/
void fetch_total_moves(t_source_stack **stack1, t_source_stack **stack2);
void quickets_moves(t_source_stack **stack1, t_source_stack **stack2);

/*---QUICK SORT----*/
void quick_sort(t_source_stack **stack);
void sort(t_source_stack **stack1, t_source_stack **stack2);



/*-----HELPERS-----*/
int check_comaprison(const char *s1, const char *s2);
int check_sign(char sign);
int ft_isdigit(char c);
long int	ft_atoi(const char *str);
int return_abs(int number);
void error(t_source_stack **stack_a, t_source_stack **stack_b);
void free_stack(t_source_stack **stack);
int valid_input(char **argv);

/*--Operations to be committted --*/
void push_a(t_source_stack **stack1, t_source_stack **stack2);
void push_b(t_source_stack **stack1, t_source_stack **stack2);
void swap_a(t_source_stack **stack1);
void swap_b(t_source_stack **stack2);
void swap_both(t_source_stack **stack1, t_source_stack **stack2);
void rotate_a(t_source_stack **stack1);
void rotate_b(t_source_stack **stack2);
void rotate_both(t_source_stack **stack1, t_source_stack **stack2);
void reverse_rotate_a(t_source_stack **stack);
void reverse_rotate_b(t_source_stack **stack);
void reverse_rotate_both(t_source_stack **stack1, t_source_stack **stack2);
void execute_moves(t_source_stack **stack_a, t_source_stack **stack_b, int moves_a , int moves_b);


#endif