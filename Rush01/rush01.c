/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:57:43 by arthur            #+#    #+#             */
/*   Updated: 2024/12/04 13:46:36 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_check_vertical_repeat(int line_vertical[], int array_size)
{
	int	i;
	int	j;

	i = 0;
	while (i < array_size)
	{
		j = 0;
		while (j < i)
		{
			if (line_vertical[i] == line_vertical[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_calcul_l_r(int line[], int array_size)
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

int	ft_calcul_r_l(int line[], int array_size)
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

int	ft_calcul_temp_u_d(int **grid, int index_current)
{
	int	i;
	int	temp;
	int	view_count;

	i = 0;
	temp = line_vertical[0];
	view_count = 1;
	while (i < index_current)
	{
		if (temp < line_vertical[i])
		{
			view_count++;
			temp = line_vertical[i];
		}
		i++;
	}
	return (view_count);
}

int	ft_calcul_temp_d_u(int **grid, int index_current)
{
	int	i;
	int	temp;
	int	view_count;

	i = index_current - 1;
	temp = line_vertical[i];
	view_count = 1;
	while (i >= 0)
	{
		if (temp < line_vertical[i])
		{
			view_count++;
			temp = line_vertical[i];
		}
		i--;
	}
	return (view_count);
}



int	ft_check_repeat(int **grid, int size_hor, int size_ver)
{
	int	i;
	int	j;
	int	cursor;

	i = 0;
	while (i < size_hor)
	{
		cursor = 0;
		while (cursor < size_ver)
		{
			j = 0;
			while (j < cursor)
			{
				if (grid[i][j] == grid[i][cursor])
					return (0);
				j++;
			}
			cursor++;
		}
		i++;
	}
	return (1);
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

void	ft_fill_poss(int line[], int **poss, int *i, int l, int r)
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
			ft_fill_poss(line, poss, i, l + 1, r);
			ft_swap(&line[l], &line[j]);
			j++;
		}
	}
}

int	**ft_malloc_poss(int size)
{
	int	**poss;
	int	nb_poss;
	int	i;
	int	j;
	
	nb_poss = ft_factorial(size);
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
		if (!grid[i])
		{
			j = 0;
			while (j < i)
				free(grid[j++]);
			free(grid);
			return (NULL);
		}
		i++;
	}
	return (grid);
}

int	main(int argc, char *argv[])
{
	int	line[] = {1, 2, 3, 4};
	int	line_length = 4;
	int	**poss;
	int	**grid;
	
	grid = ft_malloc_grid(4, 4); // Modifier le 4 avec une variable
	poss = ft_malloc_poss(line_length);
	
	int	i = 0;
	ft_fill_poss(line, poss, &i, 0, line_length - 1);
	
	
	for (int i = 0, k = 0; i < 4; i++) // On parcours chaque ligne de la grille
	{
		do
		{
			for (int j = 0; j < 4; j++)
			{
				grid[i][j] = poss[k][j];
			}
			k++;
		}
		while ( WRONG );
	}

	for (int i = 0; i < 4; i++)
	{
		printf("%d ", grid[0][i]);
	}



/* 	// Affiche la grille
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%d ", grid[i][j]);
		}
		printf("\n");
	} */

	// Affiche toutes les possibilites
/* 	for (int i = 0; i < 24; i++) // 24 est hardcode et est egal a ft_factorial
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%i", poss[i][j]);
		}
		printf("\n");
	} */
}