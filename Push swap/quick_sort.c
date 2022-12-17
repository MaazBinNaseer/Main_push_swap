#include "push_swap.h"

static int high_index(t_source_stack *stack)
{
    int index;

    index = stack->index;
    while (stack)
    {
        if(stack->index > index)
            index = stack->index;
        stack = stack->next_value;
    }
    return (index);
}

void quick_sort(t_source_stack **stack)
{
    int highest;

    if(sorted(*stack))
        return ;
    highest = high_index(*stack);
    if((*stack)->index == highest)
        rotate_a(stack);
    else if ((*stack)->next_value->index == highest)
        reverse_rotate_a(stack);
    if((*stack)->index > (*stack)->next_value->index)
        swap_a(stack);
}