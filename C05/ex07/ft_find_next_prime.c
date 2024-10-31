/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 02:39:10 by arthur            #+#    #+#             */
/*   Updated: 2024/10/31 02:46:27 by arthur           ###   ########.fr       */
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

int	ft_find_next_prime(int nb)
{
	if (ft_is_prime(nb))
		return (nb);
	nb++;
	while (ft_is_prime(nb) == 0)
		nb++;
	return (nb);
}

/* #include <stdio.h>
int	main(void)
{
	printf("%d", ft_find_next_prime(8));
} */