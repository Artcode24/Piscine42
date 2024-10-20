/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouzy <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 02:18:17 by agouzy            #+#    #+#             */
/*   Updated: 2024/10/19 03:13:39 by agouzy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_alphanum(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	i = 0;
	while (str[i] != '\0')
	{
		if (ft_is_alphanum(str[i]) && (str[i] >= 'a' && str[i] <= 'z'))
			if (!ft_is_alphanum(str[i - 1]))
				str[i] -= 32;
		i++;
	}
	return (str);
}

/*
#include <stdio.h>
int	main(void)
{
	char str[] = "HELLO";
	printf("%s", ft_strcapitalize(str));

}
*/
