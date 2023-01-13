/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbin-nas <mbin-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:09:10 by mbin-nas          #+#    #+#             */
/*   Updated: 2023/01/13 19:06:15 by mbin-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				moves_a;
	int				moves_b;
	struct s_stack	*next;
}					t_stack;

t_stack				*fill_stack_values(int argc, int arr_len, char **av);
void				assign_index(t_stack *stack_a, int ac);
int					check_sorted(t_stack *stack);
void				quick_sort(t_stack **stack);
void				sort(t_stack **stack_a, t_stack **stack_b);
int					get_lowest_index_position(t_stack **stack);
void				fetch_target_position(t_stack **stack_a, t_stack **stack_b);
void				fetch_moves(t_stack **stack_a, t_stack **stack_b);
void				do_quickest_move(t_stack **stack_a, t_stack **stack_b);
void				execute_moves(t_stack **a, t_stack **b, int moves_a,
						int moves_b);
char				**ft_split(char const *str, char c);
void				push_a(t_stack **stack_a, t_stack **stack_b);
void				push_b(t_stack **stack_a, t_stack **stack_b);
void				swap_a(t_stack **stack_a);
void				swap_b(t_stack **stack_b);
void				ss(t_stack **stack_a, t_stack **stack_b);
void				rotate_a(t_stack **stack_a);
void				rotate_b(t_stack **stack_b);
void				do_rr(t_stack **stack_a, t_stack **stack_b);
void				do_rrr(t_stack **stack_a, t_stack **stack_b);
void				rev_rot_a(t_stack **stack_a);
void				rev_rot_b(t_stack **stack_b);
t_stack				*get_stack_bottom(t_stack *stack);
t_stack				*get_stack_before_bottom(t_stack *stack);
t_stack				*stack_new(int value);
void				add_element_to_bottom(t_stack **stack, t_stack *new);
int					fetch_stack_size(t_stack *stack);
void				free_stack(t_stack **stack);
int					ft_atoi(const char *str, int ac, char **av);
void				ft_putstr(char *str);
int					abs_value(int nb);
void				exit_error(char **argv, t_stack **stack_a,
						t_stack **stack_b);
int					is_correct_input(char **av);
int					digit(char c);
int					sign(char c);
int					nbstr_cmp(const char *s1, const char *s2);
void				free_myself(char **argv);
void				exit_error2(void);
void				call_for_help(int ac, char **av);

#endif