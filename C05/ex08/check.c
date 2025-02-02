/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 08:05:47 by arthur            #+#    #+#             */
/*   Updated: 2025/02/02 08:16:33 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ten_queens_puzzle.h"

int	row_is_f(int row)
{
	int	i;

	i = 0;
	while (i < SIZE)
	{
		if (g_grid[row][i] == 1)
			return (1);
		i++;
	}
	return (0);
}

int	diag_l_is_f(int row, int col)
{
	int	i;
	int	j;

	i = row + 1;
	j = col + 1;
	while (i < SIZE && j < SIZE)
	{
		if (g_grid[i][j] == 1)
			return (1);
		i++;
		j++;
	}
	i = row - 1;
	j = col - 1;
	while (i >= 0 && j >= 0)
	{
		if (g_grid[i][j] == 1)
			return (1);
		i--;
		j--;
	}
	return (0);
}

int	diag_r_is_f(int row, int col)
{
	int	i;
	int	j;

	i = row - 1;
	j = col + 1;
	while (i >= 0 && j < SIZE)
	{
		if (g_grid[i][j] == 1)
			return (1);
		i--;
		j++;
	}
	i = row + 1;
	j = col - 1;
	while (i < SIZE && j >= 0)
	{
		if (g_grid[i][j] == 1)
			return (1);
		i++;
		j--;
	}
	return (0);
}
