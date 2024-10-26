/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 02:04:42 by arthur            #+#    #+#             */
/*   Updated: 2024/10/25 19:27:26 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
void	ft_putnbr_base(int nbr, char *base)
{
	// int base_len = ft_strlen(base);
	int base_len = 16;
	
	while (nbr > 1)
	{
		printf("%c", nbr / base_len + '0');
		printf("%c", base[nbr % base_len]);
		nbr /= base_len;
	}
	printf("\n");
}


int	main(void)
{
	ft_putnbr_base(30, "0123456789ABCDEF");
}