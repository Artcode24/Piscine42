/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 02:41:38 by arthur            #+#    #+#             */
/*   Updated: 2024/12/30 22:18:44 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	square(int nb)
{
	return (nb * nb);
}

int	*ft_map(int *tab, int length, int(*f)(int))
{
	int	i;
	int	*return_tab;

	return_tab = malloc(sizeof(int) * length);

	i = 0;
	while (i < length)
	{
		return_tab[i] = f(tab[i]);
		i++;
	}

	return (return_tab);
}

int	main(void)
{
	int	tab[] = {2, 4, 5, 8, 9};
	int	*return_tab;

	return_tab = ft_map(tab, 5, &square);
	
	for (int i = 0; i < 5; i++)
	{
		printf("%d\n", return_tab[i]);
	}
}