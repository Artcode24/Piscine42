/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:57:43 by arthur            #+#    #+#             */
/*   Updated: 2024/12/15 17:39:02 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_calcul_left(int **grid, int size, int exp_left, int current_row)
{
	int	i;
	int	temp;
	int	view_count;

	i = 0;
	temp = grid[current_row][0];
	view_count = 1;
	while (i < size)
	{
		if (temp < grid[current_row][i])
		{
			view_count++;
			temp = grid[current_row][i];
		}
		i++;
	}
	
	if (view_count == exp_left)
		return (1);
	else
		return(0);
}

int	ft_calcul_right(int **grid, int size, int exp_right, int current_row)
{
	int	i;
	int	temp;
	int	view_count;

	i = size - 1;
	temp = grid[current_row][size - 1];
	view_count = 1;
	while (i >= 0)
	{
		if (temp < grid[current_row][i])
		{
			view_count++;
			temp = grid[current_row][i];
		}
		i--;
	}
	
	if (view_count == exp_right)
		return (1);
	else
		return(0);
}

int	ft_calcul_up(int **grid, int size, int exp_up[], int current_row)
{
	int	i;
	int	col;
	int	view_count;
	int	temp;

	col = 0;
	while (col < size)
	{
		view_count = 1;
		temp = grid[0][col];
		i = 0;
		while (i < current_row)
		{
			if (temp < grid[i][col])
			{
				view_count++;
				temp = grid[i][col];
			}
			i++;
		}
		if (view_count > exp_up[col])
			return (0);
		if (current_row == size - 1 && view_count != exp_up[col])
			return (0);
		col++;
	}

	return (1);
}

int	ft_calcul_down(int **grid, int size, int exp_down[], int current_row)
{
	int	i;
	int	col;
	int	view_count;
	int	temp;

	col = 0;
	while (col < size)
	{
		view_count = 1;
		temp = grid[current_row][col];
		i = current_row - 1;
		while (i >= 0)
		{
			if (temp < grid[i][col])
			{
				view_count++;
				temp = grid[i][col];	
			}
			i--;
		}
		if (view_count > exp_down[col])
			return (0);
		col++;	
	}


	return (1);
}

int	ft_check_repeat(int **grid, int size, int current_row)
{
	int	i;
	int	col;
	
	col = 0;
	while (col < size)
	{
		i = 0;
		while (i < current_row)
		{
			if (grid[current_row][col] == grid[i][col])
				return (0);
			i++;
		}
		col++;
	}
	
	return (1);
}

int	ft_check_all(int **grid, int size_hor, int current_row, int exp_left, int exp_right, int exp_up[], int exp_down[])
{
	if (!(ft_calcul_left(grid, size_hor, exp_left, current_row)))
		return (0);
	if (!(ft_calcul_right(grid, size_hor, exp_right, current_row)))
		return (0);
	if (!(ft_calcul_up(grid, size_hor, exp_up, current_row)))
		return (0);
	if (!(ft_calcul_down(grid, size_hor, exp_down, current_row)))
		return (0);
	if (!(ft_check_repeat(grid, size_hor, current_row)))
		return (0);
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

void	ft_fill_poss(int charset[], int **poss, int *i, int l, int r)
{
	int	j;

	if (l == r)
	{
		j = 0;
		while (j < 4)
		{
			poss[*i][j] = charset[j];
			j++;
		}
		(*i)++;
	}
	else
	{
		j = l;
		while (j <= r)
		{
			ft_swap(&charset[l], &charset[j]);
			ft_fill_poss(charset, poss, i, l + 1, r);
			ft_swap(&charset[l], &charset[j]);
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

int	**ft_malloc_grid(int grid_size)
{
	int	**grid;
	int	i;
	int	j;

	grid = malloc(grid_size * sizeof(int *));
	if (!grid)
		return (NULL);

	i = 0;
	while (i < grid_size)
	{
		grid[i] = malloc(grid_size * sizeof(int));
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

int	**ft_malloc_views(int argc)
{
	int	**views;
	int	i;
	int	j;

	views = malloc(argc * sizeof(int *));
	if (!views)
		return (NULL);

	i = 0;
	j = 0;
	while (i < argc)
	{
		views[i] = malloc(sizeof(int));
		if (!views[i])
		{
			while (j < i)
			{
				free(views[j++]);
			}
			free(views);
			return (NULL);
		}
		i++;
	}
	return (views);
}

int	ft_atoi(int nb)
{
	return (nb -= 48);
}

int	**ft_get_views(int argc, char *argv[])
{
	int	**views;
	int	i;
	int	j;
	int	n;

	views = ft_malloc_views((argc / 4) * sizeof(int *));
	
	i = 0;
	n = 0;
	while (i < argc / 4)
	{
		j = 0;
		while (j < argc / 4)
		{
			views[i][j] = ft_atoi(argv[n][0]);
			n++;
			j++;
		}
		i++;
	}
	return (views);
}

/* int	main(int argc, char *argv[])
{
	int	charset[] = {1, 2, 3, 4};
	int	line_length = 4;
	int	**poss;
	int	**grid;
	int	grid_size;

	grid_size = argc / 4;
	
	grid = ft_malloc_grid(grid_size);
	poss = ft_malloc_poss(line_length);
	
	int	i = 0;
	ft_fill_poss(charset, poss, &i, 0, line_length - 1);
	
	
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
		while (  ); // CONDITIONS NOT MET
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
	}
} */