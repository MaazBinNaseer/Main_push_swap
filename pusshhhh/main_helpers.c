/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbin-nas <mbin-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:48:51 by mbin-nas          #+#    #+#             */
/*   Updated: 2023/01/18 18:55:42 by mbin-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	call_for_help(int ac, char **av)
{
	int	i;
	int	j;

	if (ac < 2)
		return ;
	i = 1;
	while (i < ac)
	{
		if (av[i][0] == '\0')
			exit_error2();
		i++;
	}
	i = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j] == ' ')
			j++;
		if (av[i][j] == '\0')
			exit_error2();
		i++;
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

size_t	ft_strlen(const char *c)
{
	size_t	l;

	l = 0;
	while (c[l] != '\0')
	{
		l++;
	}
	return (l);
}

char	*ft_strjoin(char *str1, char *str2, int flag)
{
	char	*result;
	size_t	i;
	size_t	j;

	if (!str1 || !str2)
		return (NULL);
	result = malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (str1 != NULL && str1[j] != '\0')
		result[i++] = str1[j++];
	j = 0;
	while (str2 != NULL && str2[j] != '\0')
		result[i++] = str2[j++];
	result[i++] = '\0';
	if (flag == 1)
		free(str1);
	return (result);
}
