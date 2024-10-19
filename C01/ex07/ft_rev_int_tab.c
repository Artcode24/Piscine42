/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouzy <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 00:14:50 by agouzy            #+#    #+#             */
/*   Updated: 2024/10/17 00:25:59 by agouzy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	j = size - 1;
	while (i < size / 2)
	{
		temp = tab[i];
		tab[i] = tab[j];
		tab[j] = temp;
		i++;
		j--;
	}
}

/*
#include <stdio.h>
int	main(void)
{
	int	tab[] = {1, 2, 3, 4, 5, 6};
	int	size;
	int	i;
	
	i = 0;
	size = sizeof(tab) / sizeof(tab[0]);

	ft_rev_int_tab(tab, size);
	
	while (i < size)
		printf("%i", tab[i++]);
	printf("\n");
}
*/
