/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 01:12:40 by arthur            #+#    #+#             */
/*   Updated: 2024/12/31 01:26:31 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_compare(int a, int b)
{
	return (a - b);
}

int	ft_is_sort(int *tab, int length, int(*f)(int, int))
{
	int	i;

	i = 0;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i+1]) > 0)
			return (0);
		i++;
	}
	return (1);
}

#include <stdio.h>

int	main(void)
{
	int	tab[] = {1, 2, 3, 6, 5};

	int sorted = ft_is_sort(tab, 5, ft_compare);

	printf("%d", sorted);
}