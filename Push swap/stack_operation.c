/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:19:16 by mbin-nas          #+#    #+#             */
/*   Updated: 2022/12/16 00:03:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//* New Stack Creation
t_source_stack *new_stack(int data)
{
    t_source_stack *new_stack;
    
    new_stack = malloc(sizeof * new_stack);
    if(!new_stack)
        return (NULL);
    new_stack->data = data;
    new_stack->index = 0;
    new_stack->next_value = NULL;
    new_stack->target = -1;
    new_stack->moves_a = -1;
    new_stack->moves_b = -1;
    new_stack->position = -1;
    return(new_stack);
}

t_source_stack *get_last_position(t_source_stack *stack)
{
    while(stack && stack->next_value != NULL)
        stack = stack->next_value;
    return (stack);
}

t_source_stack *get_second_last_position(t_source_stack *stack)
{
    while(stack && stack->next_value && stack->next_value->next_value != NULL)
        stack = stack->next_value;
    return (stack);    
}

void add_data_to_bottom_stack(t_source_stack **stack, t_source_stack *new_stack)
{
    t_source_stack *end_place;
    
    if(!new_stack)
        return ;
    while(!*stack)
    {
        *stack = new_stack;
        return ;
    }
    end_place = get_last_position(*stack);
    end_place->next_value = new_stack;
}

//? Get the size of the stack 
int fetch_stack_size(t_source_stack *stack)
{
    int stack_size;

    stack_size = 0;
    if(!stack)
        return (0);
    while(stack)
    {
        stack = stack->next_value;
        stack_size++;
    }
    return (stack_size);
}

