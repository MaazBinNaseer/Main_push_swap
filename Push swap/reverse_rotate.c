/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbin-nas <mbin-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:42:24 by mbin-nas          #+#    #+#             */
/*   Updated: 2022/12/15 15:55:37 by mbin-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void reverse_rotate(t_source_stack **stack)
{
    t_source_stack *temp;
    t_source_stack *end_position;
    t_source_stack *secondlast_position;
    
    end_position = get_last_position(*stack);
    secondlast_position = get_second_last_position(*stack);
    temp = *stack;
    *stack = end_position;
    (*stack)->next_value = temp;
    secondlast_position->next_value = NULL;
}

void reverse_rotate_a(t_source_stack **stack)
{
    reverse_rotate(stack);
    write(1, "rra\n", 4);
}

void reverse_rotate_b(t_source_stack **stack)
{
    reverse_rotate(stack);
    write(1, "rrb\n", 4);
}

void reverse_rotate_both(t_source_stack **stack1, t_source_stack **stack2)
{
    reverse_rotate(stack1);
    reverse_rotate(stack2);
    write(1, "rrr\n", 4);
}