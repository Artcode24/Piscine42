/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:57:43 by arthur            #+#    #+#             */
/*   Updated: 2024/11/14 08:26:35 by arthur           ###   ########.fr       */
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


int	main(void)
{
	int	line[4] = {0, 0, 0, 0};
	int	index;
	int	base;

	index = 0;
	base = 4;

	for (; index < 4; index++)
		ft_fill(line, index, base);
	
	for (int i = 0; i < 4; i++)
		printf("%d ", line[i]);
	printf("\n");
}