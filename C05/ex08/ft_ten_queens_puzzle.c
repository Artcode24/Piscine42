/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 00:51:30 by arthur            #+#    #+#             */
/*   Updated: 2025/01/26 04:50:11 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#define SIZE 10

int GRID[SIZE][SIZE];

void print_grid(void)
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf("%d ", GRID[i][j]);
        }
        printf("\n");
    }
}

void init_grid(void)
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            GRID[i][j] = 0;
        }
    }
}

int row_is_filled(int row)
{
    for (int i = 0; i < SIZE; i++)
    {
        if (GRID[row][i] == 1)
            return (1);
    }
    return (0);
}

int diag_left_is_filled(int row, int col)
{
	for (int i = row + 1, j = col + 1; i < SIZE && j < SIZE; i++, j++)
	{
		if (GRID[i][j] == 1)
			return (1);
	}

	for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
	{
		if (GRID[i][j] == 1)
			return (1);
	}
	
	return (0);
}

int diag_right_is_filled(int row, int col)
{
	for (int i = row - 1, j = col + 1; i < SIZE && j < SIZE; i--, j++)
	{
		if (GRID[i][j] == 1)
			return (1);
	}

	for (int i = row + 1, j = col -1; i < SIZE && j < SIZE; i++, j--)
	{
		if (GRID[i][j] == 1)
			return (1);
	}
	
	return (0);
}

int solve(int col)
{
    if (col == SIZE) // Toutes les colonnes sont remplies
        return (1);

    for (int row = 0; row < SIZE; row++) // Parcourir les lignes
    {
        if (!row_is_filled(row) && !diag_left_is_filled(row, col) && !diag_right_is_filled(row, col)) // Vérifie si la ligne n'est pas occupée
        {
            GRID[row][col] = 1; // Place une reine à cette position

            if (solve(col + 1)) // Appel récursif pour la colonne suivante
                return (1);

            GRID[row][col] = 0; // Backtracking
        }
    }

    return (0); // Aucun placement possible pour cette colonne
}

int ft_ten_queens_puzzle(void)
{
    if (solve(0)) // Démarre à la première colonne
    {
        print_grid(); // Affiche la grille si une solution est trouvée
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
    init_grid();
    ft_ten_queens_puzzle();
    return (0);
}
