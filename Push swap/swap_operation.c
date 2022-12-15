/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbin-nas <mbin-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:01:07 by mbin-nas          #+#    #+#             */
/*   Updated: 2022/12/15 15:49:44 by mbin-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void swap(t_source_stack *stack)
{
    int temp; 

    if(stack == NULL || stack->next_value == NULL)
        return ;
    temp = stack->data;
    stack->data = stack->next_value->data;
    stack->next_value->data = temp;
    temp = stack->index;
    stack->index = stack->next_value->index;
    stack->next_value->index = temp;
}

void swap_a(t_source_stack **stack1)
{
    swap(*stack1);
    write(1, "sa\n", 3);
}

void swap_b(t_source_stack **stack2)
{
    swap(*stack2);
    write(1, "sb\n", 3);   
}

void swap_both(t_source_stack **stack1, t_source_stack **stack2)
{
    swap(*stack1);
    swap(*stack2);
    write(1, "ss\n", 3);
}