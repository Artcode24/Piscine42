/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:57:43 by arthur            #+#    #+#             */
/*   Updated: 2024/12/02 21:54:19 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_check_line(int line[], int array_size)
{
	int	i;
	int	j;

	i = 0;
	while (i < array_size)
	{
		j = 0;
		while (j < i)
		{
			if (line[i] == line[j])
				return (0);
			j++;
		}
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

int	ft_check_all(int line[], int line_cross[], int array_size, int exp, int exp_reverse)
{
	if (!ft_check_line(line_cross, array_size))
		return (0);
	if (!(ft_calcul_line(line, array_size) == exp))
		return (0);
	if (!(ft_reverse_calcul_line(line, array_size) == exp_reverse))
		return (0);
	return (1);
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
	
	
	// Etat initial de la grille (1,2,3,4 partout)
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			grid[i][j] = poss[0][j];
		}
	}

	/* for (int i = 0; i < 4; i++) // On parcours chaque ligne de la grille
	{
		
	} */

	int test[] = {4, 2, 1, 4};
	printf("%d", ft_check_line(test, 4));
	



/* 	// Affiche la grille
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%d ", grid[i][j]);
		}
		printf("\n");
	} */

	/* // Affiche toutes les possibilites
	for (int i = 0; i < nb_poss; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%c", poss[i][j]);
		}
		printf("\n");
	} */
}