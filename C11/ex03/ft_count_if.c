/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 00:59:36 by arthur            #+#    #+#             */
/*   Updated: 2024/12/31 01:12:16 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_check_t(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 't')
			return (1);
		i++;
	}
	return (0);
}

int	ft_count_if(char **tab, int length, int(*f)(char*))
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (i < length)
	{
		if (f(tab[i]))
			count++;
		i++;
	}
	return (count);
}

int	main(void)
{
	char	*tab[] = {"Salut", "comment", "ca va?"};

	int count = ft_count_if(tab, 3, &ft_check_t);

	printf("%d", count);
}