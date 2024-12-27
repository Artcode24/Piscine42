/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 00:37:56 by arthur            #+#    #+#             */
/*   Updated: 2024/12/27 17:32:17 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <libgen.h>
#include <stdlib.h>

#define BUFF_SIZE 1024

int	ft_count_n(char *str)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			n++;
		i++;
	}
	return (n);
}

void	ft_printerror(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(2, &str[i], 1);
		i++;
	}
}

void	ft_putstr(char *str, int count)
{
	int	i;
	int	n;

	n = 0;
	count -= 10;
	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int	fd;
	int	i;
	char	buf[BUFF_SIZE];
	ssize_t	num_read;
	int	n;
	int	count;

	i = 1;
	count = 0;
	
	fd = open(argv[i], O_RDONLY);
	if (fd == -1)
	{
		ft_printerror(strerror(errno));
		ft_printerror(": ");
		ft_printerror(basename(argv[i]));
		ft_printerror("\n");
	}
	else
	{
		num_read = read(fd, buf, BUFF_SIZE);

		while (num_read > 0)
		{
			n = ft_count_n(buf);
			num_read = read(fd, buf, BUFF_SIZE);
		}

		num_read = read(fd, buf, BUFF_SIZE);
		while (num_read > 0)
		{
			ft_putstr(buf, 10);
			num_read = read(fd, buf, BUFF_SIZE);
		}
	}
	close(fd);

	fd = open(argv[i], O_RDONLY);
	num_read = read(fd, buf, BUFF_SIZE);
	while (num_read > 0)
	{	
		write(1, buf, num_read);
		num_read = read(fd, buf, BUFF_SIZE);
	}
	close(fd);	
}