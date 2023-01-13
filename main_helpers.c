/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbin-nas <mbin-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:48:51 by mbin-nas          #+#    #+#             */
/*   Updated: 2023/01/12 20:15:13 by mbin-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	call_for_help(int ac, char **av)
{
	int	i;

	if (ac < 2)
		exit(1);
	i = 1;
	while (i < ac)
	{
		if (av[i][0] == '\0')
			exit_error2();
		i++;
	}
	i = 0;
	while (av[1])
	{
		while (av[1][i] == ' ')
			i++;
		if (av[1][i] == '\0')
			exit_error2();
		break ;
	}
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}
