/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouzy <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 00:27:12 by agouzy            #+#    #+#             */
/*   Updated: 2024/10/17 00:58:29 by agouzy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	swap1;
	int	swap2;
	int	temp;

	i = 0;
	swap1 = 1;
	while (swap1 == 1)
	{
		swap2 = 0;
		i = 0;
		while (i < size - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				temp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = temp;
				swap2 = 1;
			}
		}
		i++;
		swap1 = swap2;
	}
}

/*
#include <stdio.h>
int	main(void)
{
	int	tab[] = {3, 5, 1, 8, 6, 9, 7, 6};
	int	size;
	int	i;
	
	i = 0;
	size = sizeof(tab) / sizeof(tab[0]);	
	ft_sort_int_tab(tab, size);
	
	while (i < size)
	{
		printf("%i", tab[i]);
		i++;
	}
	printf("\n");
}
*/
