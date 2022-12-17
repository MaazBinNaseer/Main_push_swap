/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_inputs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:07:36 by mbin-nas          #+#    #+#             */
/*   Updated: 2022/12/16 13:18:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ! ---- CHECK FOR DUPLICATES -------- !
static int check_duplciates(char **argv)
{
    int i;
    int j;

    i = 1;
    while(argv[i])
    {
        j = 1;
        while(argv[j])
        {
            if (j != i && check_comaprison(argv[i], argv[j]) == 0)
                    return (1);
            j++;
        }
        i++;
    }
    return (0);
}

// *-- CHECK FOR ARGUMENTS TO BE ZERO --- *
static int check_zero_args(char *argv)
{
    int i;
    
    i = 0;
    if(check_sign(argv[i]))
        i++;
    while(argv[i] && argv[i] == '0')
        i++;
    if(argv[i] != '\0')
        return (0);
    return (1);
}

//* -- CHECK FOR ARGUMENTS TO BE NUMBERS -- *
static int check_args_nbrs(char *argv)
{
    int i;
    
    i = 0;
    if(check_sign(argv[i]) && argv[i + 1] != '\0')
        i++;
    while(argv[i] && ft_isdigit(argv[i]))
        i++;
    if(argv[i] != '\0' && !ft_isdigit(argv[i]))
        return (0);
    return (1);
}

// * --- VALID INPUT -- *
int valid_input(char **argv)
{
    int i;
    int zero_check;

    zero_check = 0;
    i = 1;
    while(argv[i])
    {
        if(!check_args_nbrs(argv[i]))
            return (0);
        zero_check += check_zero_args(argv[i]);
        i++;
    }
    if(zero_check > 1)
        return (0);
    if(check_duplciates(argv))
        return (0);
    return (1); 
}