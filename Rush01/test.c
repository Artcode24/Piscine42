#include <stdio.h>

int	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_permute(int line[], int l, int r)
{
	int	i;

	if (l == r)
	{
		i = 0;
		while (i < 3)
		{
			printf("%c", line[i]);
			i++;
		}
		printf("\n");
	}
	else
	{
		i = l;
		while (i <= r)
		{
			ft_swap(&line[l], &line[i]);
			ft_permute(line, l + 1, r);
			ft_swap(&line[l], &line[i]);
			i++;
		}
	}

}

int	main(void)
{
	int	str[] = {'A', 'B', 'C'};
	int	n = 3;
	ft_permute(str, 0, n - 1);
}