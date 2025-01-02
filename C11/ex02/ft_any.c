/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 22:19:49 by arthur            #+#    #+#             */
/*   Updated: 2024/12/30 22:46:02 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_check_char(char *tab)
{
	int	i;

	i = 0;
	while (tab[i] != '\0')
	{
		if (tab[i] == 'z')
		{
			return(2);
		}
		i++;
	}
	
	return (0);
}

int	ft_any(char **tab, int(*f)(char*))
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		if (f(tab[i]) != 0)
			return (1);
		i++;
	}
	return (0);
}

int	main(void)
{
	char	*tab[] = {"Salut", "comment", "caz va?", NULL};

	int n = ft_any(tab, ft_check_char);

	printf("%d", n);
}