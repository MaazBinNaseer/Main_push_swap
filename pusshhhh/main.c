/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbin-nas <mbin-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:06:54 by mbin-nas          #+#    #+#             */
/*   Updated: 2023/01/22 18:20:48 by mbin-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdbool.h>

void	free_myself(char **argv)
{
	int	i;

	i = -1;
	while (argv[++i])
		free(argv[i]);
	free(argv);
}

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
		swap_a(stack_a);
	else if (stack_size == 3)
		quick_sort(stack_a);
	else if (stack_size > 3 && !check_sorted(*stack_a))
		sort(stack_a, stack_b);
}

int	main(int ac, char **av)
{
	char	**args;
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;

	call_for_help(ac, av);
	stack_b = NULL;
	if (ac > 1)
		args = parsing(av);
	else
		return (0);
	if (!is_correct_input(args))
		exit_error(args, NULL, NULL);
	stack_a = fill_stack_values(arrlen(args), args);
	stack_size = fetch_stack_size(stack_a);
	assign_index(stack_a, stack_size + 1);
	push_swap(&stack_a, &stack_b, stack_size);
	free_myself(args);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
