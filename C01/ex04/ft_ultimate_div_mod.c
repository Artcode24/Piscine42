/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouzy <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 21:24:30 by agouzy            #+#    #+#             */
/*   Updated: 2024/10/16 21:32:13 by agouzy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	div;

	div = *a / *b;
	*b = *a % *b;
	*a = div;
}

/*
#include <stdio.h>
int	main(void)
{
	int	a;
	int	b;

	a = 8;
	b = 5;
	ft_ultimate_div_mod(&a, &b);
	
	printf("a = %i, b = %i\n", a, b);
}
*/
