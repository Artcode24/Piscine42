/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:57:43 by arthur            #+#    #+#             */
/*   Updated: 2024/11/16 04:00:33 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

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

void	ft_fill(int line[], int index, int base)
{
	int	number;

	number = base;
	while (number <= base + 3)
	{
		if (ft_check(line, index, (number - 1) % 4 + 1))
		{
			line[index] = (number - 1) % 4 + 1;
			return;	
		}
		number++;
	}
}

int	ft_calcul_line(int line[], int array_size)
{
	int	i;
	int	temp;
	int	view_count;

	i = 0;
	temp = line[0];
	view_count = 1;
	while (i < array_size)
	{
		if (temp < line[i])
		{
			view_count++;
			temp = line[i];
		}
		i++;
	}
	return (view_count);
}

int	main(int argc, char *argv[])
{
	int	line[4] = {0, 0, 0, 0};
	int	index;
	int	base;

	index = 0;
	base = 1;

	while (index < 4)
	{
		ft_fill(line, index, base);
		index++;
	}
	
	for (int i = 0; i < 4; i++)
		printf("%d ", line[i]);
	printf("\n");
}