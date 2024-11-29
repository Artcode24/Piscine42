/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:57:43 by arthur            #+#    #+#             */
/*   Updated: 2024/11/28 17:47:53 by arthur           ###   ########.fr       */
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

int	ft_reverse_calcul_line(int line[], int array_size)
{
	int	i;
	int	temp;
	int	view_count;

	i = array_size - 1;
	temp = line[i];
	view_count = 1;
	while (i >= 0)
	{
		if (temp < line[i])
		{
			view_count++;
			temp = line[i];
		}
		i--;
	}
	return (view_count);
}

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_permute(int line[], int possibilities[][4], int *i, int l, int r)
{
	int	j;

	if (l == r)
	{
		j = 0;
		while (j < 4)
		{
			possibilities[*i][j] = line[j];
			j++;
		}
		(*i)++;
	}
	else
	{
		j = l;
		while (j <= r)
		{
			ft_swap(&line[l], &line[j]);
			ft_permute(line, possibilities, i, l + 1, r);
			ft_swap(&line[l], &line[j]);
			j++;
		}
	}

}

int	main(int argc, char *argv[])
{
	int	line[] = {'A', 'B', 'C', 'D'};
	int	n = 4;
	int	possibilities[24][4];
	
	int	i = 0;
	ft_permute (line, possibilities, &i, 0, n - 1);

	for (int i = 0; i < 24; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%c", possibilities[i][j]);
		}
		printf("\n");
	}
}