/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finding_position.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbin-nas <mbin-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 18:23:45 by mbin-nas          #+#    #+#             */
/*   Updated: 2022/12/15 18:58:44 by mbin-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void fetch_position(t_source_stack **stack)
{
    t_source_stack *temp;
    int             i;
    
    temp = *stack;
    i = 0;
    while(temp)
    {
        temp->position = i;
        temp = temp->next_value;
        i++;
    }
}

int get_low_point_index(t_source_stack **stack)
{
    t_source_stack *temp;
    int lowpoint_index;
    int lowpoint_position;

    temp = *stack;
    lowpoint_index = INT_MAX;
    fetch_position(stack);
    lowpoint_position = temp->position;
    while(temp)
    {
        if(temp->index < lowpoint_index)
        {
            lowpoint_index = temp->index;
            lowpoint_position = temp->position;
        }
        temp = temp->next_value;
    }  
    return (lowpoint_position);  
}

static int fetch_target(t_source_stack **stack, int element_bindx, int target_index, int target_position)
{
        t_source_stack *temp_a;
        temp_a = *stack;

        while(temp_a)
        {
            if(temp_a->index > element_bindx && temp_a->index < target_index)
            {
                target_index = temp_a->index;
                target_index = temp_a->position;
            }
            temp_a = temp_a->next_value;
        }
    return (target_position);
}

void fetch_target_position(t_source_stack **stack_a, t_source_stack **stack_b)
{
    t_source_stack *temp_b;
    int target_position;
    
    temp_b = *stack_b;
    fetch_position(stack_a);
    fetch_position(stack_b);
    target_position = 0;
    while(temp_b)
    {
        target_position = fetch_target(stack_a, temp_b->index, INT_MAX, target_position);
        temp_b->target = target_position;
        temp_b = temp_b->next_value;
    }
    
}