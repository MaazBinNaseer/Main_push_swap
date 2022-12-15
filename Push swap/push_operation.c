/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbin-nas <mbin-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:49:58 by mbin-nas          #+#    #+#             */
/*   Updated: 2022/12/15 15:46:44 by mbin-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void push(t_source_stack **stack1, t_source_stack **stack2)
{
    t_source_stack *temp;

    if(*stack1 = NULL)
        return ;
    temp = (*stack1)->next_value;
    (*stack1)->next_value = *stack2;
    *stack2 = *stack1;
    *stack1 = temp;
}

void push_a(t_source_stack **stack1, t_source_stack **stack2)
{
    push(stack2, stack1);
    write(1, "pa\n", 3);
}

void push_b(t_source_stack **stack1, t_source_stack **stack2)
{
    push(stack1, stack2);
    write(1, "pb\n", 3);
}