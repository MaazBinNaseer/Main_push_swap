/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbin-nas <mbin-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 13:54:53 by mbin-nas          #+#    #+#             */
/*   Updated: 2023/01/22 18:19:09 by mbin-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

void	exit_error(char **argv, t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a == NULL || *stack_a != NULL)
		free_stack(stack_a);
	if (stack_b == NULL || *stack_b != NULL)
		free_stack(stack_b);
	if (argv != NULL)
		free_myself(argv);
	write(2, "Error\n", 6);
	exit(1);
}
/*
* @brief Handles the overflow of the atoi inputs
*/

void	ft_atoi_overflow(unsigned int nb, int sign, char **av)
{
	if (nb > 2147483647 && sign == 1)
	{
		exit_error(av, NULL, NULL);
	}
	if (nb > 2147483648 && sign == -1)
		exit_error(av, NULL, NULL);
}

/*
* @brief ft_atoi handles the cases of the numbers that are parsed 
*/
int	ft_atoi(const char *str, char **av)
{
	unsigned int	nb;
	unsigned int	prev;
	int				isneg;
	int				i;
	int				sign;

	nb = 0;
	isneg = 1;
	i = -1;
	sign = 1;
	if (str[0] == '-' || str[0] == '+')
	{
		isneg = 1 - 2 * (str[++i] == '-');
		sign *= -1;
	}
	while (digit(str[++i]))
	{
		prev = nb;
		nb = (nb * 10) + (str[i] - '0');
		if (prev > nb)
			exit_error(av, NULL, NULL);
	}
	ft_atoi_overflow(nb, sign, av);
	return (nb * isneg);
}

/* Get the distance from 0 whether it is positive or negative*/
int	abs_value(int nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}
