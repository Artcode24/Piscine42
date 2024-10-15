/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouzy <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 01:05:17 by agouzy            #+#    #+#             */
/*   Updated: 2024/10/16 01:09:17 by agouzy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

/*
#include <stdio.h>
int	main(void)
{
	int	a;
	int	b;
	int	div;
	int	mod;

	a = 8;
	b = 5;

	ft_div_mod(a, b, &div, &mod);
	printf("div = %i, mod = %i\n", div, mod);
}
*/
