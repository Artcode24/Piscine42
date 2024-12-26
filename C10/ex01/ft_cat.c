/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 23:34:35 by arthur            #+#    #+#             */
/*   Updated: 2024/12/26 17:29:31 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <libgen.h>

#define BUFF_SIZE 30720

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

void	ft_display_file(char *file)
{
	int	fd;
	ssize_t numRead;
	char	buf[BUFF_SIZE];

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_printerror(strerror(errno));
		ft_printerror(": ");
		ft_printerror(basename(file));
		ft_printerror("\n");
	}

	numRead = read(fd, buf, BUFF_SIZE);

	while (numRead > 0)
	{
		write(1, buf, numRead);
		numRead = read(fd, buf, BUFF_SIZE);
	}
	close(fd);
}

int	main(int argc, char *argv[])
{
	int	i;

	i = 1;
	ft_display_file(argv[i]);
}