/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 14:04:00 by mbin-nas          #+#    #+#             */
/*   Updated: 2022/12/20 21:56:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}


static void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	if (stack_size == 2 && !check_sorted(*stack_a))
		do_sa(stack_a);
	else if (stack_size == 3)
		quick_sort(stack_a);
	else if (stack_size > 3 && !check_sorted(*stack_a))
		sort(stack_a, stack_b);
}


int arrlen(char **arr) {
	int i;

	i = 0;
	while(arr[i]) {
		i++;
	}
	return i;
}

int	main(int ac, char **av)
{
	char **args;	
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;

	if (ac < 2)
		return (0);
	stack_b = NULL;
	if (ac == 2)
		args = ft_split(av[1], ' ');
	else
		args = &av[1];
	if (!is_correct_input(args))
		exit_error(NULL, NULL);
	stack_a = fill_stack_values(arrlen(args), args);
	stack_size = fetch_stack_size(stack_a);
	assign_index(stack_a, stack_size + 1);
	push_swap(&stack_a, &stack_b, stack_size);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
