/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbin-nas <mbin-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:13:15 by mbin-nas          #+#    #+#             */
/*   Updated: 2022/12/15 18:35:09 by mbin-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stdio.h"
# include "stdlib.h"
# include "unistd.h"
# include <limits.h>

//* Creating of the stack data
typedef struct s_source_stack
{
	int						data;
	int						index;
	int						position;
	int						target;
	int						moves_a;
	int						moves_b;
	struct s_source_stack	*next_value;
}							t_source_stack;

/*--stack operation--*/
t_source_stack *get_last_position(t_source_stack *stack);
t_source_stack *get_second_last_position(t_source_stack *stack);


/*-----HELPERS-----*/
int check_comaprison(const char *s1, const char *s2);
int check_sign(char sign);
int ft_isdigit(char c);

#endif