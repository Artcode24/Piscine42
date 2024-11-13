/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 02:04:42 by arthur            #+#    #+#             */
/*   Updated: 2024/11/13 04:10:36 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

long	ft_strlen(char *base)
{
	int	len;

	len = 0;
	while (base[len] != '\0')
		len++;
	return (len);
}

int	ft_same_char(char *base, int len)
{
	int		i;
	int		j;

	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr_base_recursive(long nbr, char *base, long base_len)
{
	if (nbr >= base_len)
		ft_putnbr_base_recursive(nbr / base_len, base, base_len);
	ft_putchar(base[nbr % base_len]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		i;
	long	base_len;
	long	nbr_long;

	nbr_long = (long)nbr;
	i = 0;
	base_len = ft_strlen(base);
	if (nbr_long < 0)
	{
		nbr_long *= -1;
		ft_putchar('-');
	}
	if (base_len < 2)
		return ;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return ;
		i++;
	}
	if (ft_same_char(base, base_len))
		return ;
	ft_putnbr_base_recursive(nbr_long, base, base_len);
}

/* 
int	main(void)
{
	ft_putnbr_base(-2147483648, "0123456789ABCDEF");
} */