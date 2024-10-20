/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouzy <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 00:29:23 by agouzy            #+#    #+#             */
/*   Updated: 2024/10/20 00:44:13 by agouzy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	len;
	unsigned int	i;

	len = 0;
	while (src[len] != '\0')
		len++;
	i = 0;
	while (src[i] != '\0' && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (len);
}

/*
#include <stdio.h>
int	main(void)
{
	char dest[20];
	unsigned int	len;

	len = ft_strlcpy(dest, "Hello world", 3);

	printf("len = %i, dest = %s\n", len, dest);
}
*/
