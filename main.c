/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbin-nas <mbin-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:06:54 by mbin-nas          #+#    #+#             */
/*   Updated: 2023/01/12 17:53:07 by mbin-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	arrlen(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		i++;
	}
	return (i);
}

int	main(int ac, char **av)
{
	char	**args;
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;

	call_for_help(ac, av);
	stack_b = NULL;
	if (ac == 2)
		args = ft_split(av[1], ' ');
	else
		args = &av[1];
	if (!is_correct_input(args) && ac == 2)
		exit_error(args, NULL, NULL);
	if (!is_correct_input(args) && ac > 2)
		exit_error2();
	stack_a = fill_stack_values(ac, arrlen(args), args);
	stack_size = fetch_stack_size(stack_a);
	assign_index(stack_a, stack_size + 1);
	push_swap(&stack_a, &stack_b, stack_size);
	if (ac == 2)
		free_myself(args);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
