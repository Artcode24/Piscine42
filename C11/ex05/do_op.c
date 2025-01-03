/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 17:38:51 by arthur            #+#    #+#             */
/*   Updated: 2025/01/03 02:21:56 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "utils.h"
#include "utils_2.h"

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

	if (argc != 4)
		return (-1);

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