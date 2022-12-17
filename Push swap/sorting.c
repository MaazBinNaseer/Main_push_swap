#include "push_swap.h"

static void push_all_three_data(t_source_stack **stack1, t_source_stack **stack2)
{
    int stack_size;
    int pushed;
    int i;

    stack_size = fetch_stack_size(*stack1);
    pushed = 0;
    i = 0;
    while(stack_size > 6 && i < stack_size && pushed < stack_size / 2)
    {
        if((*stack1)->index <= stack_size / 2)
        {
            push_b(stack1, stack2);
            pushed++;
        }
        else
            rotate_a(stack1);
        i++;
    }
    while(stack_size - pushed > 3)
    {
        push_b(stack1, stack2);
        pushed++;
    }
}

static void shift_the_stack(t_source_stack **stack1)
{
    int lowest_point;
    int stack_size;

    stack_size = fetch_stack_size(*stack1);
    lowest_point = get_low_point_index(stack1);
    if(lowest_point > stack_size / 2)
    {
        while (lowest_point < stack_size)
        {
            reverse_rotate_a(stack1);
            lowest_point++;
        }
    }
    else
    {
        while(lowest_point > 0)
        {
            rotate_a(stack1);
            lowest_point--;
        }
    }
}

void sort(t_source_stack **stack1, t_source_stack **stack2)
{
    push_all_three_data(stack1, stack2);
    quick_sort(stack1);
    while(*stack2)
    {
        fetch_target_position(stack1, stack2);
        fetch_total_moves(stack1, stack2);
        quickets_moves(stack1, stack2);
    }
    if(!sorted(*stack1))
        shift_the_stack(stack1);
}