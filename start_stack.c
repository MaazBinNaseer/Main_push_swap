/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbin-nas <mbin-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:07:20 by mbin-nas          #+#    #+#             */
/*   Updated: 2023/01/12 17:59:33 by mbin-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stop_the_filling(int argc, char **av, int arr_len)
{
	int			i;
	long int	nb;

	i = 0;
	nb = 0;
	while (i < arr_len)
	{
		nb = ft_atoi(av[i], argc, av);
		if (nb > INT_MAX || nb < INT_MIN)
		{
			if (argc == 2)
				exit_error(av, NULL, NULL);
			exit_error2();
		}
		i++;
	}
}

t_stack	*fill_stack_values(int argc, int arr_len, char **av)
{
	t_stack		*stack_a;
	long int	nb;
	int			i;

	stack_a = NULL;
	nb = 0;
	i = 0;
	stop_the_filling(argc, av, arr_len);
	while (i < arr_len)
	{
		nb = ft_atoi(av[i], argc, av);
		if (nb > INT_MAX || nb < INT_MIN)
		{
			if (argc == 2)
				exit_error(av, &stack_a, NULL);
			exit_error2();
		}
		if (i == 0)
			stack_a = stack_new((int)nb);
		else
			add_element_to_bottom(&stack_a, stack_new((int)nb));
		i++;
	}
	return (stack_a);
}

void	assign_index(t_stack *stack_a, int stack_size)
{
	t_stack	*ptr;
	t_stack	*highest;
	int		value;

	while (--stack_size > 0)
	{
		ptr = stack_a;
		value = INT_MIN;
		highest = NULL;
		while (ptr)
		{
			if (ptr->value == INT_MIN && ptr->index == 0)
				ptr->index = 1;
			if (ptr->value > value && ptr->index == 0)
			{
				value = ptr->value;
				highest = ptr;
				ptr = stack_a;
			}
			else
				ptr = ptr->next;
		}
		if (highest != NULL)
			highest->index = stack_size;
	}
}
