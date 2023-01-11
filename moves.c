/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbin-nas <mbin-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:07:12 by mbin-nas          #+#    #+#             */
/*   Updated: 2023/01/11 13:54:44 by mbin-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * *@brief Fetch the total moves to move the things into the correct position
 * 	* 	into the stack A from stack B 
 * * MOVES_a : Represent the top of the stack 
 * * MOVES_b: Represent the botttom of the stack
 * * Total moves to be allocated to be returned and therefore, calculated.
*/
void	fetch_moves(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		size_a;
	int		size_b;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	size_a = fetch_stack_size(tmp_a);
	size_b = fetch_stack_size(tmp_b);
	while (tmp_b)
	{
		tmp_b->moves_b = tmp_b->pos;
		if (tmp_b->pos > size_b / 2)
			tmp_b->moves_b = (size_b - tmp_b->pos) * -1;
		tmp_b->moves_a = tmp_b->target_pos;
		if (tmp_b->target_pos > size_a / 2)
			tmp_b->moves_a = (size_a - tmp_b->target_pos) * -1;
		tmp_b = tmp_b->next;
	}
}

/*
* @brief This is to work with efficient of the code 
* @example this would allow the moves to be calculated and therefore, 
* getting the sorting to be done quicker. 
*/

void	do_quickest_move(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		cheapest;
	int		moves_a;
	int		moves_b;

	tmp = *stack_b;
	cheapest = INT_MAX;
	while (tmp)
	{
		if (abs_value(tmp->moves_a)
			+ abs_value(tmp->moves_b) < abs_value(cheapest))
		{
			cheapest = abs_value(tmp->moves_b) + abs_value(tmp->moves_a);
			moves_a = tmp->moves_a;
			moves_b = tmp->moves_b;
		}
		tmp = tmp->next;
	}
	execute_moves(stack_a, stack_b, moves_a, moves_b);
}
