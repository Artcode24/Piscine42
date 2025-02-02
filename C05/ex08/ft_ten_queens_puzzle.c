/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 00:51:30 by arthur            #+#    #+#             */
/*   Updated: 2025/01/31 07:10:59 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#define SIZE 10

int g_grid[10][10];
int c_count = 0;

void init_grid(void)
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            g_grid[i][j] = 0;
        }
    }
}

int row_is_filled(int row)
{
    for (int i = 0; i < SIZE; i++)
    {
        if (g_grid[row][i] == 1)
            return (1);
    }
    return (0);
}

int diag_left_is_filled(int row, int col)
{
	for (int i = row + 1, j = col + 1; i < SIZE && j < SIZE; i++, j++)
	{
		if (g_grid[i][j] == 1)
			return (1);
	}

	for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
	{
		if (g_grid[i][j] == 1)
			return (1);
	}
	
	return (0);
}

int diag_right_is_filled(int row, int col)
{
	for (int i = row - 1, j = col + 1; i < SIZE && j < SIZE; i--, j++)
	{
		if (g_grid[i][j] == 1)
			return (1);
	}

	for (int i = row + 1, j = col -1; i < SIZE && j < SIZE; i++, j--)
	{
		if (g_grid[i][j] == 1)
			return (1);
	}
	
	return (0);
}

void	print_positions()
{
	for (int col = 0; col < SIZE; col++)
	{
		for (int row = 0; row < SIZE; row++)
		{
			if(g_grid[row][col])
			{
				printf("%d", row);
			}
		}
	}
	printf("\n");
}

void solve(int col)
{
    if (col == SIZE) // Toutes les colonnes sont remplies
    {
	c_count++;
	print_positions();
    }

    for (int row = 0; row < SIZE; row++) // Parcourir les lignes
    {
        if (!row_is_filled(row) && !diag_left_is_filled(row, col) && !diag_right_is_filled(row, col))
        {
		g_grid[row][col] = 1;
		solve(col + 1);
		g_grid[row][col] = 0;
        }
    }
}

int ft_ten_queens_puzzle(void)
{
	solve(0);
	return (c_count);
}

/* 
int 	main(void)
{
	init_grid();
	int count = ft_ten_queens_puzzle();
	printf("\n%d\n", count);
	return (0);
} 
 */