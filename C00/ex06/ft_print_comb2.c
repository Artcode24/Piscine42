/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouzy <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 10:43:54 by agouzy            #+#    #+#             */
/*   Updated: 2024/10/07 01:55:01 by agouzy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_put_one_digit(int x)
{
	ft_putchar('0');
	ft_putchar(x + '0');
}

void	ft_put_two_digits(int x, int y)
{
	ft_putchar(x + '0');
	ft_putchar(y + '0');
}

void	ft_putnbr(int a, int b)
{
	if (a <= 9)
		ft_put_one_digit(a);
	else
		ft_put_two_digits(a / 10, a % 10);
	write(1, " ", 1);
	if (b <= 9)
		ft_put_one_digit(b);
	else
		ft_put_two_digits(b / 10, b % 10);
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	while (a <= 98)
	{
		b = a + 1;
		while (b <= 99)
		{
			ft_putnbr(a, b);
			if (!(a == 98 && b == 99))
				write(1, ", ", 2);
			b++;
		}
		a++;
	}
}

/*
int	main(void)
{
	ft_print_comb2();
	return (0);
}
*/
