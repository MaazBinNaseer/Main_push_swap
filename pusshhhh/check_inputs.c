/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_inputs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbin-nas <mbin-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:07:52 by mbin-nas          #+#    #+#             */
/*   Updated: 2023/01/22 15:37:25 by mbin-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	sign(char c)
{
	return (c == '+' || c == '-');
}

// int	nbstr_cmp(const char *s1, const char *s2)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = i;
// 	if (s1[i] == '+')
// 	{
// 		if (s2[j] != '+')
// 			i++;
// 	}
// 	else
// 	{
// 		if (s2[j] == '+')
// 			j++;
// 	}
// 	while (s1[i] != '\0' && s2[j] != '\0' && s1[i] == s2[j])
// 	{
// 		i++;
// 		j++;
// 	}
// 	return ((unsigned char)s1[i] - (unsigned char)s2[j]);
// }
