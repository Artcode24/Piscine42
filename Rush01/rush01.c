/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:57:43 by arthur            #+#    #+#             */
/*   Updated: 2024/11/30 19:46:21 by arthur           ###   ########.fr       */
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

int	ft_factorial(int nb)
{
	if (nb == 1)
		return (1);
	else
		return (nb * ft_factorial(nb - 1));
}

void	ft_permute(int line[], int **poss, int *i, int l, int r)
{
	int	j;

	if (l == r)
	{
		j = 0;
		while (j < 4)
		{
			poss[*i][j] = line[j];
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
			ft_permute(line, poss, i, l + 1, r);
			ft_swap(&line[l], &line[j]);
			j++;
		}
	}
}

int	**ft_malloc_poss(int size, int nb_poss)
{
	int	**poss;
	int	i;
	int	j;
	
	poss = malloc(nb_poss * sizeof(int *));
	if (!poss)
		return (NULL);

	i = 0;
	while (i < nb_poss)
	{
		poss[i] = malloc(size * sizeof(int));
  		if (!poss[i])
		{
			j = 0;
			while (j < i)
				free(poss[j++]);
			free(poss);
			return (NULL);
		}
		i++;
	}
	return (poss);
}

int	**ft_malloc_grid(int size_x, int size_y)
{
	int	**grid;
	int	i;
	int	j;

	grid = malloc(size_y * sizeof(int *));
	if (!grid)
		return (NULL);

	i = 0;
	while (i < size_x)
	{
		grid[i] = malloc(size_x * sizeof(int));
		i++;
		if (!grid[i])
		{
			j = 0;
			while (j < i)
				free(grid[j++]);
			free(grid);
			return (NULL);
		}
	}
	return (grid);
}

int	main(int argc, char *argv[])
{
	int	line[] = {'1', '2', '3', '4'};
	int	n = 4;
	int	**poss;
	int 	nb_poss;

	nb_poss = ft_factorial(n);
	poss = ft_malloc_poss(n, nb_poss);
	
	int	i = 0;
	ft_permute (line, poss, &i, 0, n - 1);

	for (int i = 0; i < nb_poss; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%c", poss[i][j]);
		}
		printf("\n");
	}
}