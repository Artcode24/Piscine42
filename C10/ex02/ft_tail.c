/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 00:37:56 by arthur            #+#    #+#             */
/*   Updated: 2024/12/27 23:28:38 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <libgen.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_atoi(char *s)
{
	
}

void	ft_print_error(char *str)
{
	int	i;

	i = 0;
	while (str[i++] != '\0')
		write(2, &str[i], 1);
}

char	*ft_display_file(char *file, char *to_read, int n)
{
	int	fd;
	ssize_t	num_read;
	char	buf[n];
	char	temp[n];
	int 	i;
	int	current_index;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_print_error(strerror(errno));
		ft_print_error(basename(file));
	}
	else
	{
		num_read = read(fd, buf, n);

		while (num_read > 0)
		{
			current_index = 0;
			while (current_index < num_read)
			{
				temp[current_index] = buf[current_index];
				current_index++;
			}
				
			num_read = read(fd, buf, n);
		}

		i = 0;
		while (i < n)
		{
			to_read[i] = temp[current_index % n];
			i++;
			current_index++;
		}
	}
	return (to_read);
}

int main(int argc, char *argv[])
{
	char	*to_read;
	int	i;
	int	j;
	int	n;

	n = ft_atoi(argv[2]);

	to_read = malloc(sizeof(char) * n);
	
	i = 3;
	to_read = ft_display_file(argv[i], to_read, n);

	j = 0;
	while (j < n)
	{
		write(1, &to_read[j++], 1);
	}
}