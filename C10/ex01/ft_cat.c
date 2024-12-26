/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 23:34:35 by arthur            #+#    #+#             */
/*   Updated: 2024/12/26 00:47:44 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

#define BUFF_SIZE 1024

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(2, &str[i], 1);
		i++;
	}
}

// Create ft_display_file function
// 

int	main(int argc, char *argv[])
{
	int	fd;
	int	i;
	char	buf[BUFF_SIZE];
	char	str[12];
	ssize_t numRead;

	i = 1;

	fd = open(argv[i], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr(strerror(errno));
		return (1);
	}
	else
	{
		numRead = read(fd, buf, BUFF_SIZE);

		while (numRead > 0)
		{
			write(1, buf, numRead);
			numRead = read(fd, buf, BUFF_SIZE);
		}
		close(fd);
	}
	i++;
	
	while (i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd == -1)
		{
			ft_putstr(strerror(errno));
			return (1);
		}
		else
		{
			numRead = read(fd, buf, BUFF_SIZE);

			while (numRead > 0)
			{
				write(1, buf, numRead);
				numRead = read(fd, buf, BUFF_SIZE);
			}
			close(fd);
		}
		i++;
	}
	
}