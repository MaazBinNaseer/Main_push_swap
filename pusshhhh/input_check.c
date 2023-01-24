/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbin-nas <mbin-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:33:54 by mbin-nas          #+#    #+#             */
/*   Updated: 2023/01/22 18:20:16 by mbin-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	have_duplicates(char **av)
{
	int	i;
	int	j;
	int	num;
	int	num1;

	i = 0;
	while (av[i])
	{
		j = 1;
		while (av[j] && j != i)
		{
			num = ft_atoi(av[i], av);
			num1 = ft_atoi(av[j], av);
			if (num == num1)
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

static int	arg_is_number(char *av)
{
	int	i;

	i = 0;
	if (sign(av[i]) && av[i + 1] != '\0')
		i++;
	while (av[i] && digit(av[i]))
		i++;
	if (av[i] != '\0' && !digit(av[i]))
		return (0);
	return (1);
}

// static int	arg_is_zero(char *av)
// {
// 	int	i;

// 	i = 0;
// 	if (sign(av[i]))
// 		i++;
// 	while (av[i] && av[i] == '0')
// 		i++;
// 	if (av[i] != '\0')
// 		return (0);
// 	return (1);
// }

int	is_correct_input(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (!arg_is_number(av[i]))
			return (0);
		i++;
	}
	if (have_duplicates(av))
		return (0);
	return (1);
}
