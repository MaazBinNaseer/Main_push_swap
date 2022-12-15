/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbin-nas <mbin-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:20:47 by mbin-nas          #+#    #+#             */
/*   Updated: 2022/12/15 15:49:02 by mbin-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void rotate(t_source_stack **stack)
{
    t_source_stack *temp;
    t_source_stack *end_position;
    
    temp = *stack;
    *stack = (*stack)->next_value;
    end_position = get_last_position(*stack);
    temp->next_value = NULL;
    end_position->next_value = temp;   
}

void rotate_a(t_source_stack **stack1)
{
    rotate(stack1);
    write(1, "ra\n", 3);
}

void rotate_b(t_source_stack **stack2)
{
    rotate(stack2);
    write(1, "rb\n", 3);
}

void rotate_both(t_source_stack **stack1, t_source_stack **stack2)
{
    rotate(stack1);
    rotate(stack2);
    write(1, "rr\n", 3);
}