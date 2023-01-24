/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soritng.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbin-nas <mbin-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:12:44 by mbin-nas          #+#    #+#             */
/*   Updated: 2023/01/17 22:01:34 by mbin-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* 
*	Push three elements and save the last three to sort 
*/
static void	push_all_save_three(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size;
	int	pushed;
	int	i;

	stack_size = fetch_stack_size(*stack_a);
	pushed = 0;
	i = 0;
	while (stack_size > 6 && i < stack_size && pushed < stack_size / 2)
	{
		if ((*stack_a)->index <= stack_size / 2)
		{
			push_b(stack_a, stack_b);
			pushed++;
		}
		else
			rotate_a(stack_a);
		i++;
	}
	while (stack_size - pushed > 3)
	{
		push_b(stack_a, stack_b);
		pushed++;
	}
}

/* Revert the smallest to the top of the stack after everything has sorted*/
static void	shift_stack(t_stack **stack_a)
{
	int	lowest_pos;
	int	stack_size;

	stack_size = fetch_stack_size(*stack_a);
	lowest_pos = get_lowest_index_position(stack_a);
	if (lowest_pos > stack_size / 2)
	{
		while (lowest_pos < stack_size)
		{
			rev_rot_a(stack_a);
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			rotate_a(stack_a);
			lowest_pos--;
		}
	}
}

/* sort:
*	Sorting algorithm for a stack larger than 3.
*		Push everything but 3 numbers to stack B.
*		Sort the 3 numbers left in stack A.
*		Calculate the most cost-effective move.
*		Shift elements until stack A is in order.
*/
void	sort(t_stack **stack_a, t_stack **stack_b)
{
	push_all_save_three(stack_a, stack_b);
	quick_sort(stack_a);
	while (*stack_b)
	{
		fetch_target_position(stack_a, stack_b);
		fetch_moves(stack_a, stack_b);
		do_quickest_move(stack_a, stack_b);
	}
	if (!check_sorted(*stack_a))
		shift_stack(stack_a);
}
