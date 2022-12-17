#include "push_swap.h"

int sorted(t_source_stack *stack)
{
    while (stack->next_value != NULL)
    {
        if (stack->data > stack->next_value->data)
            return (0);
        stack = stack->next_value;
    }
    return (1);
}

static void push_swap(t_source_stack **stack1, t_source_stack **stack2, int stack_size)
{
    if(stack_size == 2 && !sorted(*stack1))
        swap_a(stack1);
    else if (stack_size == 3)
        quick_sort(stack1);
    else if (stack_size > 3 && !sorted(*stack1))
        sort(stack1, stack2);
}

int main(int argc , char **argv)
{
    t_source_stack *stack1;
    t_source_stack *stack2;
    int stack_size;

    if(argc < 2)
        return (0);
    if(!valid_input(argv))
        error(NULL, NULL);
    stack2 = NULL;
    stack1 = fill_stack(argc, argv);
    stack_size = fetch_stack_size(stack1);
    put_index_on_data(stack1, stack_size + 1);
    push_swap(&stack1, &stack2, stack_size);
    free_stack(&stack1);
    free_stack(&stack2);
    return (0);
}
