#include "push_swap.h"

//# -- Starts filling the stack with the user values -- # 
t_source_stack *fill_stack(int argc, char **argv)
{
    t_source_stack *stack_a;
    long int num;
    int      i;

    stack_a = NULL; 
    num = 0;
    i= 1;
    while(i < argc)
    {
        num = ft_atoi(argv[i]);
        if(num > INT_MAX || num < INT_MIN)
            error(&stack_a, NULL);
        if (i == 1)
            stack_a = new_stack((int)num) ;
        else  
            add_data_to_bottom_stack(&stack_a, new_stack((int)num));
        i++;
    }
    return (stack_a);
}

//* Puts the args positions index to recongnize the position of the values 
void put_index_on_data(t_source_stack *stack_a, int stack_size)
{
    t_source_stack *ptr;
    t_source_stack *highest_value;
    int value;

    while(--stack_size > 0)
    {
        ptr = stack_a;
        value = INT_MIN;
        highest_value = NULL;
        while(ptr)
        {
            if(ptr->data == INT_MIN && ptr->index == 0)
                ptr->index = 1;
            if(ptr->data > value && ptr->index == 0)
            {
                value = ptr->data;
                highest_value = ptr;
                ptr = stack_a;
            }
            else
                ptr = ptr->next_value;
        }
    if (highest_value != NULL)
        highest_value->index = stack_size; 
    }
}