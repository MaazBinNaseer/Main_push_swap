/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbin-nas <mbin-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:33:37 by mbin-nas          #+#    #+#             */
/*   Updated: 2023/01/06 16:11:53 by mbin-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
* @brief Looks for the highest value inside the stack 
* @example [0] [5] [7]
*                  [^] is the highest value in the stack 
*/
static int	find_highest_index(t_stack *stack)
{
	int	index;

	index = stack->index;
	while (stack)
	{
		if (stack->index > index)
			index = stack->index;
		stack = stack->next;
	}
	return (index);
}

/*
* @brief Quick sort the stack 
* 
*/
void	quick_sort(t_stack **stack)
{
	int	highest;

	if (check_sorted(*stack))
		return ;
	highest = find_highest_index(*stack);
	if ((*stack)->index == highest)
		rotate_a(stack);
	else if ((*stack)->next->index == highest)
		rev_rot_a(stack);
	if ((*stack)->index > (*stack)->next->index)
		swap_a(stack);
}
