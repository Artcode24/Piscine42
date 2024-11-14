/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:57:43 by arthur            #+#    #+#             */
/*   Updated: 2024/11/14 01:51:39 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_check(int line[], int index, int number)
{
	int	i;

	i = 0;
	while (i < index)
	{
		if (line[i] == number)
			return (0);
		i++;
	}
	return (1);
}

void	ft_fill(int line[], int index, int size)
{
	int	number;

	number = 1;
	while (number <= size)
	{
		if (ft_check(line, index, number))
			{
				line[index] = number;	
				index++;	
			}
		number++;
	}
}


int	main(void)
{
	int	line[4] = {1, 4, 0, 0};
	int	size;
	int	index;

	index = 2;
	size = 4;

	while (index < size)
	{
		ft_fill(line, index, size);
		index++;
	}

	int i = 0;
	while (i < size)
	{
		printf("%d\n", line[i]);
		i++;
	}
}