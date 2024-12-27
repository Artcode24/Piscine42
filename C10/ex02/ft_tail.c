/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 00:37:56 by arthur            #+#    #+#             */
/*   Updated: 2024/12/27 01:29:59 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <libgen.h>
#include <stdlib.h>

#define BUFF_SIZE 1024

void	ft_putstr(int display, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(display, &str[i], 1);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int	fd;
	int	i;
	char	buf[BUFF_SIZE];
	ssize_t	num_read;

	i = 1;
	
	fd = open(argv[i], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr(2, strerror(errno));
		ft_putstr(2, ": ");
		ft_putstr(2, basename(argv[i]));
		ft_putstr(2, "\n");
	}
	else
	{
		// read ...
	}
}