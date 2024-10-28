/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:21:27 by arthur            #+#    #+#             */
/*   Updated: 2024/10/28 17:08:24 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_find_index(char *base, char c)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (c == base[i])
			return i;
		i++;
	}
	return NULL;
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	nb;
	int	index;

	nb = 0;
	i = 0;
	while (str[i] != '\0')
	{
		index = ft_find_index(base, str[i])
		nb = nb * 10;
		nb += base[index] - 48;
		i++;
	}
}


#include <stdio.h>
int	main(void)
{
	
}