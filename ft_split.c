/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbin-nas <mbin-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 18:32:00 by mbin-nas          #+#    #+#             */
/*   Updated: 2023/01/13 18:45:23 by mbin-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_readwords(char const *str, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c)
			i++;
		if (str[i] != c && str[i] != '\0')
			count++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (count);
}

int	ft_wordlen(char const *str, char c)
{
	int	i;
	int	length;

	length = 0;
	i = 0;
	while (str[i] == c)
		i++;
	while (str[i] != c && str[i] != '\0')
	{
		i++;
		length++;
	}
	return (length);
}

char	**ft_split2(char const *str, char c, char **mem, int i)
{
	int	j;
	int	k;

	i = -1;
	j = 0;
	mem = (char **)malloc(sizeof(char *) * (ft_readwords(str, c) + 1));
	if (!mem)
		return (NULL);
	while (ft_readwords(str, c) > ++i)
	{
		k = 0;
		while (str[j] == c && str[j] != '\0')
			j++;
		mem[i] = (char *)malloc(sizeof(char) * ft_wordlen(&str[j], c) + 1);
		if (!mem[i])
		{
			return (NULL);
		}
		while (str[j] != c && str[j] != '\0')
			mem[i][k++] = str[j++];
		mem[i][k] = '\0';
	}
	mem[i] = 0;
	return (mem);
}

char	**ft_split(char const *str, char c)
{
	char	**mem;
	int		i;

	i = -1;
	mem = NULL;
	if (!str)
		return (NULL);
	return (ft_split2(str, c, mem, i));
}

void	exit_error2(void)
{
	write(2, "Error\n", 6);
	exit(0);
}
// int main(void)
// {
//     char **result;
//     char *test_string = "This is a test string";
//     char delimiter = ' ';
//     result = ft_split(test_string, delimiter);

//     int i = 0;
//     while (result[i])
//     {
//         printf("%s\n", result[i++]);
//     }

//     //free the memory allocated by ft_split
//     i = 0;
//     while (result[i])
//         free(result[i++]);
//     free(result);
//     return (0);
// }