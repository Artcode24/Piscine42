/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 03:30:18 by arthur            #+#    #+#             */
/*   Updated: 2025/02/02 07:50:39 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	result;
	int	a;

	result = 0;
	a = 0;
	while (result < nb)
	{
		result = a * a;
		if (result == nb)
			return (a);
		a++;
	}
	return (0);
}

/* 
#include <stdio.h>
int	main(void)
{
	printf("%d", ft_sqrt(36));
} */