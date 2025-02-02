/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 00:51:30 by arthur            #+#    #+#             */
/*   Updated: 2025/02/02 08:26:33 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_ten_queens_puzzle.h"

int	g_grid[10][10];
int	g_count = 0;

int	row_is_f(int row);
int	diag_l_is_f(int row, int col);
int	diag_r_is_f(int row, int col);

void	init_grid(void)
{
	int	i;
	int	j;

	i = 0;
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
		{
			g_grid[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	print_positions(void)
{
	int		col;
	int		row;
	char	c;

	col = 0;
	while (col < SIZE)
	{
		row = 0;
		while (row < SIZE)
		{
			if (g_grid[row][col])
			{
				c = row + '0';
				write(1, &c, 1);
			}
			row++;
		}
		col++;
	}
	write(1, "\n", 1);
}

void	solve(int col)
{
	int	row;

	if (col == SIZE)
	{
		g_count++;
		print_positions();
	}
	row = 0;
	while (row < SIZE)
	{
		if (!row_is_f(row) && !diag_l_is_f(row, col) && !diag_r_is_f(row, col))
		{
			g_grid[row][col] = 1;
			solve(col + 1);
			g_grid[row][col] = 0;
		}
		row++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	solve(0);
	return (g_count);
}

/* 
int 	main(void)
{
	init_grid();
	int count;

	count = ft_ten_queens_puzzle();
	printf("\n%d\n", count);
	return (0);
}
*/