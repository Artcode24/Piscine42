/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouzy <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 02:10:08 by agouzy            #+#    #+#             */
/*   Updated: 2024/10/19 02:24:01 by agouzy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 0 && str[i] <= 31)
			return (0);
		i++;
	}
	return (1);
}

/*
#include <stdio.h>
int	main(void)
{
	ft_str_is_printable();
}
*/
