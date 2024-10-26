/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouzy <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 03:17:01 by agouzy            #+#    #+#             */
/*   Updated: 2024/10/23 03:45:52 by agouzy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	len;

	i = 0;
	j = 0;
	len = ft_strlen(dest) + ft_strlen(src) + 1;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && i < size - 1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (len);
}

/*
#include <stdio.h>
int	main(void)
{
	char		dest[13] = "Hello";
	char		src[] = " World!";
	unsigned int	size = 12;

	printf("%d", ft_strlcat(dest, src, size));
}
*/
