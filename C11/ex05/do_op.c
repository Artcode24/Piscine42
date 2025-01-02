/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 17:38:51 by arthur            #+#    #+#             */
/*   Updated: 2025/01/02 17:33:35 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	if (s1[0] == s2[0])
		return (1);
	return (0);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		nb *= -1;
		ft_putchar('-');
	}
	if (nb <= 9)
		ft_putchar(nb + '0');
	else
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}

int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	else
		return (0);
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	nb;

	i = 0;
	sign = 1;
	nb = 0;
	while (ft_isspace(str[i]))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10;
		nb += str[i] - 48;
		i++;
	}
	return (nb * sign);
}

int	ft_mod(int a, int b)
{
	return (a % b);
}

int	ft_mul(int a, int b)
{
	return (a * b);
}

int	ft_div(int a, int b)
{
	return (a / b);
}

int	ft_sub(int a, int b)
{
	return (a - b);
}

int	ft_add(int a, int b)
{
	return (a + b);
}

int	ft_switch(char *argv[], char *operators[], int op_size, int (*func_op[])(int, int))
{
	int	a;
	int	b;
	int	i;

	a = ft_atoi(argv[1]);
	b = ft_atoi(argv[3]);

	i = 0;
	while (i < op_size)
	{
		if (ft_strcmp(argv[2], operators[i]))
			return (func_op[i](a, b));
		i++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	int	(*func_op[])(int, int) = {ft_mod, ft_mul, ft_div, ft_sub, ft_add};
	int	op_size = 5;
	char	*operators[] = {"%", "*", "/", "-", "+"};

	if (ft_strcmp(argv[2], "%") && ft_strcmp(argv[3], "0"))
	{
		ft_putstr("Stop: modulo by zero");
		ft_putstr("\n");
		return (-1);
	}
	else if (ft_strcmp(argv[2], "/") && ft_strcmp(argv[3], "0"))
	{
		ft_putstr("Stop: division by zero");
		ft_putstr("\n");
		return (-1);
	}
	
	ft_putnbr(ft_switch(argv, operators, op_size, func_op));
	ft_putstr("\n");
}