/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:57:43 by arthur            #+#    #+#             */
/*   Updated: 2024/11/28 14:25:51 by arthur           ###   ########.fr       */
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

void	ft_fill_case(int line[], int index, int min_number)
{
	int	number;

	number = min_number;
	while (number <= min_number + 3)
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

void	ft_fill_line(int line[], int min_number)
{
	int	index;

	index = 0;
	while (index < 4)
	{
		ft_fill_case(line, index, min_number);
		index++;
	}
}

int	main(int argc, char *argv[])
{
	int	line[4] = {0, 0, 0, 0};
	int	index;
	int	min_number;
	int	expected;

	// It takes a parameters to check how many boxes we should see
	if (argc != 2)
		return (1);

	expected = atoi(argv[1]);

	// This loop runs as long as we don't see the correct amount of boxes
	min_number = 1;
	while ((ft_calcul_line(line, 4) != expected) || line[0] == 0)
	{
		ft_fill_line(line, min_number);
		min_number++;
	}


	// Start the loop again while changing at least one element. > ft_line_compare
	// If it's not possible, go back to the initial state.
	// Maybe use a copy ? And use a ft_line_compare
	// Or maybe rather run an inner loop inside the first one, as long as ft_calcul == expected

	// CHANGER L'INDEX APRES LE CHIFFRE LE PLUS GRAND UNE FOIS QUE FT_CALCUL RETOURNE EXPECTED
	
	// Print the line to test
	for (int i = 0; i < 4; i++)
		printf("%d ", line[i]);
	printf("\n");
}