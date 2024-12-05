/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouzy <agouzy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 19:51:53 by agouzy            #+#    #+#             */
/*   Updated: 2024/10/13 23:20:07 by agouzy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	first_line(int a)
{
	int	i;

	i = 1;
	while (i <= a)
	{
		if (i == 1)
			ft_putchar('A');
		else if (i == a)
			ft_putchar('C');
		else
			ft_putchar('B');
		i++;
	}
	ft_putchar('\n');
}

void	last_line(int a)
{
	int	i;

	i = 1;
	while (i <= a)
	{
		if (i == 1)
			ft_putchar('C');
		else if (i == a)
			ft_putchar('A');
		else
			ft_putchar('B');
		i++;
	}
	ft_putchar('\n');
}

void	middle_line(int a)
{
	int	i;

	i = 1;
	while (i <= a)
	{
		if (i == 1 || i == a)
			ft_putchar('B');
		else
			ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
}

void	rush(int a, int b)
{
	int	i;

	i = 1;
	while (i <= b)
	{
		if (i == 1)
			first_line(a);
		else if (i == b)
			last_line(a);
		else
			middle_line(a);
		i++;
	}
}
