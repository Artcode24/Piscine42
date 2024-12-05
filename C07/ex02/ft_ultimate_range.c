/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 01:07:51 by arthur            #+#    #+#             */
/*   Updated: 2024/11/07 03:20:19 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*arr;
	int	i;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	i = 0;
	arr = malloc((max - min) * sizeof(int));
	if (!arr)
		return (-1);
	while (i + min < max)
	{
		arr[i] = i + min;
		i++;
	}
	*range = arr;
	return (max - min);
}

/* 
#include <stdio.h>
int	main(void)
{
	int	*arr = NULL;
	int	*p1 = arr;
	int	**p2 = &p1;
	

	printf("%d", ft_ultimate_range(p2, 2, 5));
} */