/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouzy <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:05:48 by agouzy            #+#    #+#             */
/*   Updated: 2024/10/23 02:29:42 by agouzy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	j = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		if (str[i] == to_find[j] && j == 0)
		{
			j++;
			start = i;
		}
		else if (str[i] == to_find[j])
			j++;
		else
			j = 0;
		if (to_find[j] == '\0')
			return (str + start);
		i++;
	}
	return (NULL);
}

/*
#include <stdio.h>
int	main(void)
{
	char *str = "Hello world!";
	char *to_find = "world";
	printf("%s", ft_strstr(str, to_find));
}
*/
