/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 00:51:30 by arthur            #+#    #+#             */
/*   Updated: 2025/01/31 04:18:40 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#define SIZE 10

int COUNT = 0;

void print_grid(int grid[10][10])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

void init_grid(int grid[10][10])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            grid[i][j] = 0;
        }
    }
}

int row_is_filled(int row, int grid[10][10])
{
    for (int i = 0; i < SIZE; i++)
    {
        if (grid[row][i] == 1)
            return (1);
    }
    return (0);
}

int diag_left_is_filled(int row, int col, int grid[10][10])
{
	for (int i = row + 1, j = col + 1; i < SIZE && j < SIZE; i++, j++)
	{
		if (grid[i][j] == 1)
			return (1);
	}

	for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
	{
		if (grid[i][j] == 1)
			return (1);
	}
	
	return (0);
}

int diag_right_is_filled(int row, int col, int grid[10][10])
{
	for (int i = row - 1, j = col + 1; i < SIZE && j < SIZE; i--, j++)
	{
		if (grid[i][j] == 1)
			return (1);
	}

	for (int i = row + 1, j = col -1; i < SIZE && j < SIZE; i++, j--)
	{
		if (grid[i][j] == 1)
			return (1);
	}
	
	return (0);
}

int	find(int grid[10][10], int col)
{
	for (int i = 0; i < SIZE; i++)
	{
		if(grid[i][col])
		{
			return (i);
		}
	}
	return (0);
}

int solve(int col, int grid[10][10])
{
    if (col == SIZE) // Toutes les colonnes sont remplies
    {
	COUNT++;
	print_grid(grid);
	printf("\n");
	for (int i = 0; i < SIZE; i++)
	{
		printf("%d", find(grid, i));
	}
	printf("\n");
	printf("\n");
	printf("\n");
    }

    for (int row = 0; row < SIZE; row++) // Parcourir les lignes
    {
        if (!row_is_filled(row, grid) && !diag_left_is_filled(row, col, grid) && !diag_right_is_filled(row, col, grid))
        {
            grid[row][col] = 1; // Place une reine à cette position
            if (solve(col + 1, grid)) // Appel récursif pour la colonne suivante
                return (1);
            grid[row][col] = 0; // Backtracking
        }
    }

    return (0); // Aucun placement possible pour cette colonne
}

int ft_ten_queens_puzzle(int grid[10][10])
{
	if (solve(0, grid)) // Démarre à la première colonne
	{
        	// print_grid(grid);
	        return (1);
	}
	else
	{
        	printf("Aucune solution trouvée\n");
        	return (0);
    	}
}

int main(void)
{
	int	grid[SIZE][SIZE];
	int	grid_copy[SIZE][SIZE];
	
	init_grid(grid);
	
	ft_ten_queens_puzzle(grid);

	return (0);
}
