/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 08:13:08 by arthur            #+#    #+#             */
/*   Updated: 2025/02/02 08:19:14 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TEN_QUEENS_PUZZLE_H
# define FT_TEN_QUEENS_PUZZLE_H

# include <stdio.h>

# define SIZE 10

extern int	g_grid[SIZE][SIZE];
extern int	g_count;
void		init_grid(void);
void		print_positions(void);
void		solve(int col);
int			ft_ten_queens_puzzle(void);
int			row_is_f(int row);
int			diag_l_is_f(int row, int col);
int			diag_r_is_f(int row, int col);

#endif
