/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 02:16:31 by arthur            #+#    #+#             */
/*   Updated: 2024/10/31 02:38:26 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	comp;

	comp = nb - 1;
	if (nb <= 1)
		return (0);
	while (comp > 1)
	{
		if (nb % comp == 0)
			return (0);
		comp--;
	}
	return (1);
}

/* 
#include <stdio.h>
int	main(void)
{
	printf("%d\n", ft_is_prime(11));
} */