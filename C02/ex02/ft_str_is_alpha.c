/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouzy <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 21:50:54 by agouzy            #+#    #+#             */
/*   Updated: 2024/10/19 02:06:19 by agouzy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int		i;
	char	c;

	i = 0;
	while (str[i] != '\0')
	{
		c = str[i];
		if (c < 'A' || (c > 'Z' && c < 'a') || c > 'z')
			return (0);
		i++;
	}
	return (1);
}

/*
#include <stdio.h>
int	main(int argc, char *argv[])
{
	if (argc != 2)
		return (1);
	printf("%i", ft_str_is_alpha(argv[1]));
}
*/
