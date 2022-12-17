#include "push_swap.h"
 
 // !--- Freeing the stack --- !
 void free_stack(t_source_stack **stack)
 {
    t_source_stack *temp;

    if(!stack || !*stack)
        return ;
    while(*stack)
    {
        temp = (*stack)->next_value;
        free(*stack);
        *stack = temp;
    }
    *stack = NULL;
 }

 // ! --- ERROR CODE EXIT -- !
 void error(t_source_stack **stack_a, t_source_stack **stack_b)
 {
    if(stack_a == NULL || *stack_a != NULL)
        free_stack(stack_a);
    if(stack_b == NULL || *stack_b != NULL)
        free_stack(stack_b);
    write(1, "There is an error\n", 19);
    exit(1);
 }