#include "push_swap.h"

static void call_reverse_rotate_both(t_source_stack **stack_a, t_source_stack **stack_b, int *moves_a, int *moves_b)
{
    while(*moves_a < 0 && *moves_b < 0)
    {
        (*moves_a)++;
        (*moves_b)++;
        reverse_rotate_both(stack_a, stack_b);
    }
}

static void call_rotate_both(t_source_stack **stack_a, t_source_stack **stack_b, int *moves_a, int *moves_b)
{
    while(*moves_a > 0 && *moves_b > 0)
    {
        (*moves_a)--;
        (*moves_b)--;
        rotate_both(stack_a, stack_b);
    }
}

static void call_rotate_a(t_source_stack **stack_a, int *moves_a)
{
    while(*moves_a)
    {
        if(*moves_a > 0)
        {
            rotate_a(stack_a);
            (*moves_a)--;
        }
        else if (*moves_a < 0)
        {
            reverse_rotate_a(stack_a);
            (*moves_a)++;
        }
    }
}

static void call_rotate_b(t_source_stack **stack_b, int *moves_b)
{
    while(*moves_b)
    {
        if(*moves_b > 0)
        {
            rotate_b(stack_b);
            (*moves_b)--;
        }
        else if (*moves_b < 0)
        {
            reverse_rotate_b(stack_b);
            (*moves_b)++;
        }
    }
}

void execute_moves(t_source_stack **stack_a, t_source_stack **stack_b, int moves_a , int moves_b)
{
    if(moves_a < 0 && moves_b < 0)
        call_reverse_rotate_both(stack_a, stack_b, &moves_a, &moves_b);
    else if (moves_a > 0 && moves_b > 0)
        call_rotate_both(stack_a, stack_b, &moves_a, &moves_b);
    call_rotate_a(stack_a, &moves_a);
    call_rotate_b(stack_b, &moves_b);
    push_a(stack_a, stack_b);
}