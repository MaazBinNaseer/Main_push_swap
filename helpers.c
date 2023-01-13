/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbin-nas <mbin-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 13:54:53 by mbin-nas          #+#    #+#             */
/*   Updated: 2023/01/13 19:11:50 by mbin-nas         ###   ########.fr       */
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

int	ft_atoi(const char *str, int ac, char **av)
{
	int 		nb;
	int			prev;
	int			isneg;
	int			i;

	(void)ac;
	(void)av;
	nb = 0;
	isneg = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		isneg = 1 - 2 * (str[i++] == '-');
	while (digit(str[i]))
	{
		prev = nb;
		nb = (nb * 10) + (str[i] - '0');
		printf("%d\n", nb);
		i++;
		
	}
	if(nb > INT_MAX)
			exit_error(av, NULL, NULL);
		// else if (prev > nb)
		// {
		// 	printf("I am getting called\n");
		// 	if (ac == 2)
		// 		{
		// 			exit_error(av, NULL, NULL);
		// 		}
		// 		exit_error2();
		// }
	exit_error2();
	return (nb * isneg);
}

/* Get the distance from 0 whether it is positive or negative*/
int	abs_value(int nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}
