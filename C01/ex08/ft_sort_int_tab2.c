/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouzy <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 00:27:12 by agouzy            #+#    #+#             */
/*   Updated: 2024/10/18 16:14:56 by agouzy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	cursor;
	int	temp;

	i = 0;

	while (i < size)
	{
		j = i;
		cursor = i;
		while (j < size)
		{
			if (tab[cursor] > tab[j])
				cursor = j;
			j++;
		}

		temp = tab[i];
		tab[i] = tab[cursor];
		tab[cursor] = temp;
		
		i++;
	}
}


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
