/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 02:11:40 by agouzy            #+#    #+#             */
/*   Updated: 2024/11/14 02:39:34 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_array(char *value, char *value_max, int n)
{
	int	i;

	i = 0;
	while (i < n)
		write(1, &value[i++], 1);
	if (value[0] != value_max[0])
		write(1, ", ", 2);
}

void	ft_print_combn(int n)
{
	char	value[9];
	char	value_max[9];
	int		index;
	int		base;

	index = 0;
	while (index < n)
	{
		value[index] = index + '0';
		value_max[index] = (10 - n) + index + '0';
		index++;
	}
	ft_print_array(value, value_max, n);
	while (value[0] < value_max[0])
	{
		index = n - 1;
		while (value[index] == value_max[index])
			index--;
		base = ++value[index];
		while (index < n - 1)
			value[++index] = ++base;
		ft_print_array(value, value_max, n);
	}
}

/* 
#include <stdlib.h>
int	main(int argc, char *argv[])
{
	if (argc != 2)
		return -1;
	ft_print_combn(atoi(argv[1]));
	return (0);
} */