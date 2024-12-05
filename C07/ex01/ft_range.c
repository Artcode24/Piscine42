/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 03:01:24 by arthur            #+#    #+#             */
/*   Updated: 2024/11/07 01:44:20 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*arr;
	int	i;

	if (min >= max)
	{
		arr = NULL;
		return (arr);
	}

	i = 0;
	arr = malloc((max - min) * sizeof(int));
	while (min < max)
	{
		arr[i] = min;
		i++;
		min++;
	}
	return (arr);
}

/* #include <stdio.h>
int	main(void)
{
	int 	min = 2;
	int	max = 5;
	int 	range = max - min;
	int	*arr = ft_range(min, max);
	int 	i = 0;

	while (i < range)
	{
		printf("%d", arr[i]);
		i++;
	}
} */