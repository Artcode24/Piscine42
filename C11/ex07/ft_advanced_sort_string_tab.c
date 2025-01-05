/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 14:34:33 by arthur            #+#    #+#             */
/*   Updated: 2025/01/04 01:48:27 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

void	ft_advanced_sort_string_tab(char **tab, int(*cmp)(char *, char *))
{
	int	i;
	int	sorted;
	char	*temp;

	if (!tab)
		return;

	sorted = 0;
	while (!sorted)
	{
		sorted = 1;
		i = 0;
		while (tab[i + 1])
		{
			if ((cmp(tab[i], tab[i + 1]) > 0))
			{
				temp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = temp;
				sorted = 0;
			}
			i++;
		}
	}
}

#include <stdio.h>

int	main(void)
{
	char	*strs[] = {"hello", "comment", "ca", "va", 0};

	for (int i = 0; strs[i]; i++)
		printf("%s\n", strs[i]);
	
	printf("\n");

	ft_advanced_sort_string_tab(strs, &ft_strcmp);

	for (int i = 0; strs[i]; i++)
		printf("%s\n", strs[i]);	
}