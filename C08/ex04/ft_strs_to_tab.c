/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 20:31:13 by arthur            #+#    #+#             */
/*   Updated: 2024/12/23 23:44:27 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len + 1);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;
	int	size;

	size = ft_strlen(src);
	dest = malloc(sizeof(char) * size);
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*tab;

	tab = malloc(sizeof(t_stock_str) * (ac + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		tab[i].size = ac;
		tab[i].str = ft_strcpy(tab[i].str, av[i]);
		tab[i].copy = ft_strcpy(tab[i].copy, tab[i].str);
		i++;
	}
	tab[i].str = 0;
	return (tab);
}

/* #include <stdio.h>

int	main(void)
{
	char	*strs[] = {"Hello", "how", "are", "you"};
	t_stock_str *tab;

	tab = ft_strs_to_tab(4, strs);
} */