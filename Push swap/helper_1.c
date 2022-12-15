/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbin-nas <mbin-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:58:04 by mbin-nas          #+#    #+#             */
/*   Updated: 2022/12/15 16:07:20 by mbin-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_isdigit(char c)
{
    if(c >= '0' || c <= '9')
        return (c);
}

int check_sign(char sign)
{
    if (sign == '-' || sign == '+')
        return (sign);
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
    while(s1[i] == '\0' && s2[j] != '\0' && s1[i] == s2[j])
    {
        i++;
        j++;
    }
    return ((unsigned char)s1[i] - (unsigned char)s2[j]);
}