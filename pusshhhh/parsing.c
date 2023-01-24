/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbin-nas <mbin-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:08:54 by mbin-nas          #+#    #+#             */
/*   Updated: 2023/01/20 17:12:00 by mbin-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

char	**parsing(char **av)
{
	char	**args;
	char	*temp;
	int		i;
	int		flag;

	flag = 0;
	i = 1;
	temp = " ";
	while (av[i])
	{
		temp = ft_strjoin(temp, av[i], flag);
		flag = 1;
		temp = ft_strjoin(temp, " ", flag);
		i++;
	}
	args = ft_split(temp, ' ');
	free(temp);
	return (args);
}
