/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouzy <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 00:45:31 by agouzy            #+#    #+#             */
/*   Updated: 2024/10/20 01:38:17 by agouzy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_atoh(char c, char *hex)
{
	int	first_char;
	int	second_char;

	first_char = c / 16;
	second_char = c % 16;
	if (first_char > 9)
		first_char += 87;
	else
		first_char += '0';
	if (second_char > 9)
		second_char += 87;
	else
		second_char += '0';
	hex[0] = first_char;
	hex[1] = second_char;
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int		i;
	char	hex[2];

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] <= 31)
		{
			ft_atoh(str[i], hex);
			ft_putchar('\\');
			ft_putchar(hex[0]);
			ft_putchar(hex[1]);
		}
		else
			ft_putchar(str[i]);
		i++;
	}
}

/*
#include <stdio.h>
int	main(void)
{
	ft_putstr_non_printable("Coucou\ntu vas bien ?");
}
*/
