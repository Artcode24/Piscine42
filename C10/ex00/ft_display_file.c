/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 19:35:00 by arthur            #+#    #+#             */
/*   Updated: 2025/01/04 01:06:02 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

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

int	main(int argc, char *argv[])
{
	int	fd;
	char	buf[BUFF_SIZE];
	ssize_t num_read;

	if (argc < 2)
	{
		ft_putstr("File name missing.\n");
		return (1);
	}
	
	if (argc > 2)
	{
		ft_putstr("Too many arguments.\n");
		return (1);
	}
		

	fd = open(argv[1], O_RDONLY);

	if (fd != -1)
	{
		num_read = read(fd, buf, BUFF_SIZE);

		while (num_read > 0)
		{
			write(1, buf, num_read);
			num_read = read(fd, buf, BUFF_SIZE);
		}
	}
	else
	{
		ft_putstr("Cannot read file.\n");
		return (1);
	}
	close(fd);
	return (0);
}