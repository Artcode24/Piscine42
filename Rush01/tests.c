#include "rush01.h"

void	test_factorial(void)
{
	if (ft_factorial(1) == 1)
		printf("ft_factorial === OK - Expected (1) Returned (%d)\n", ft_factorial(1));
	else
		printf("ft_factorial === KO - Expected (1) Returned %d\n", ft_factorial(1));
	if (ft_factorial(2) == 2)
		printf("ft_factorial === OK - Expected (2) Returned (%d)\n", ft_factorial(2));
	else
		printf("ft_factorial === KO - Expected (2) Returned %d\n", ft_factorial(2));
	if (ft_factorial(4) == 24)
		printf("ft_factorial === OK - Expected (24) Returned (%d)\n", ft_factorial(4));
	else
		printf("ft_factorial === KO - Expected (24) Returned %d\n", ft_factorial(4));
	if (ft_factorial(9) == 362880)
		printf("ft_factorial === OK - Expected (362880) Returned (%d)\n", ft_factorial(9));
	else
		printf("ft_factorial === KO - Expected (362880) Returned %d\n", ft_factorial(9));
}

void	test_calcul_left(void)
{
	
}

int	main(void)
{
	test_factorial();
	printf("\n");
	test_calcul_left();
}