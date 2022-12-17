#include "push_swap.h"

/* ------------------------------------------------------------
# The total amount of moves done by a which will result at the top is +ve
# The total amount of moves done by b which result at the bottom is -ve
------------------------------------------------------------------*/
void fetch_total_moves(t_source_stack **stack1, t_source_stack **stack2)
{
    t_source_stack *temp_1;
    t_source_stack *temp_2;
    int size_1;
    int size_2;

    temp_1 = *stack1;
    temp_2 = *stack2;
    size_1 = fetch_stack_size(temp_1);
    size_2 = fetch_stack_size(temp_2);
    while(temp_2)
    {
        temp_2->moves_b = temp_2->position;
        if(temp_2->position > size_2 / 2)
            temp_2->moves_b = (size_2 - temp_2->position) * -1;
        temp_2->moves_a = temp_2->target;
        if(temp_2->target > size_1 / 2)
            temp_2->moves_a = (size_1 - temp_2->target) * -1;
        temp_2 = temp_2->next_value;
    }
}

void quickets_moves(t_source_stack **stack1, t_source_stack **stack2)
{
    t_source_stack *temp;
    int quickest;
    int moves_a;
    int moves_b;

    temp = *stack2;
    quickest = INT_MAX;
    while (temp)
    {
        if(return_abs(temp->moves_a) + return_abs(temp->moves_b) < return_abs(quickest))
        {
            quickest = return_abs(temp->moves_b) + return_abs(temp->moves_a);
            moves_a = temp->moves_a;
            moves_b = temp->moves_b;
        }
        temp = temp->next_value;
    }
    execute_moves(stack1, stack2, moves_a, moves_b);
}