/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 01:06:47 by arthur            #+#    #+#             */
/*   Updated: 2024/10/30 01:06:58 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	else
		return (ft_recursive_factorial(nb - 1) * nb);
}

/* 
#include <stdio.h>
int	main(void)
{
	printf("%d", ft_recursive_factorial(5));
} */