/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:58:04 by mbin-nas          #+#    #+#             */
/*   Updated: 2022/12/16 12:42:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_isdigit(char c)
{
    return (c >= '0' && c <= '9');
}

int check_sign(char sign)
{
    return (sign == '-' || sign == '+');
  
}


/* -------------------------------
* Check for the comparison between strings 
----------------------------------*/

int check_comaprison(const char *s1, const char *s2)
{
    int i;
    int j;

    i = 0;
    j = i;
    if(s1[i] == '+')
    {
        if(s2[j] != '+')
            i++;
    }
    else 
    {
        if (s2[j] == '+')
            j++;
    }
    while(s1[i] != '\0' && s2[j] != '\0' && s1[i] == s2[j])
    {
        i++;
        j++;
    }
    return ((unsigned char)s1[i] - (unsigned char)s2[j]);
}

long int	ft_atoi(const char *str)
{
	long int	number;
	int			negative;
	int			i;

	number = 0;
	negative = 1;
	i = 0;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		negative *= -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		number = (number * 10) + (str[i] - '0');
		i++;
	}
	return (number * negative);
}

int return_abs(int number)
{
    if (number < 0)
        return (number * -1);
    return (number);
}