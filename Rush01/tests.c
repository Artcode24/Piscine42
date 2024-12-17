#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "rush01.h"

void	ft_free_grid(int **grid)
{
	for (int i = 0; i < 4; i++)
		free(grid[i]);
	free(grid);
}

int	**ft_create_grid(void)
{
	int **grid = malloc(sizeof(int *) * 4);
	if (!grid)
		return (NULL);

	for (int i = 0; i < 4; i++)
	{
		grid[i] = malloc(sizeof(int) * 4);
		if (!grid[i])
		{
			for (int j = 0; j < i; j++)
				free(grid[j]);
			free(grid);
			return (NULL);
		}
	}

	grid[0][0] = 1; grid[0][1] = 2; grid[0][2] = 3; grid[0][3] = 4;
	grid[1][0] = 2; grid[1][1] = 3; grid[1][2] = 4; grid[1][3] = 1;
	grid[2][0] = 3; grid[2][1] = 4; grid[2][2] = 1; grid[2][3] = 2;
	grid[3][0] = 4; grid[3][1] = 1; grid[3][2] = 2; grid[3][3] = 3;

	return (grid);
}

void	test_factorial(void)
{
	if (ft_factorial(1) == 1)
		printf("ft_factorial :) OK - Expected (1) Returned (%d)\n", ft_factorial(1));
	else
		printf("ft_factorial :( KO - Expected (1) Returned %d\n", ft_factorial(1));
	if (ft_factorial(2) == 2)
		printf("ft_factorial :) OK - Expected (2) Returned (%d)\n", ft_factorial(2));
	else
		printf("ft_factorial :( KO - Expected (2) Returned %d\n", ft_factorial(2));
	if (ft_factorial(4) == 24)
		printf("ft_factorial :) OK - Expected (24) Returned (%d)\n", ft_factorial(4));
	else
		printf("ft_factorial :( KO - Expected (24) Returned %d\n", ft_factorial(4));
	if (ft_factorial(9) == 362880)
		printf("ft_factorial :) OK - Expected (362880) Returned (%d)\n", ft_factorial(9));
	else
		printf("ft_factorial :( KO - Expected (362880) Returned %d\n", ft_factorial(9));
}

void	test_calcul_left(void)
{
	int **grid = ft_create_grid();
	
	if (ft_calcul_left(grid, 4, 4, 0) == true)
		printf("ft_calcul_left :) OK - Expected (TRUE) Returned (TRUE)\n");
	else
		printf("ft_calcul_left :( KO - Expected (TRUE) Returned (FALSE)\n");

	if (ft_calcul_left(grid, 4, 2, 0) == false)
		printf("ft_calcul_left :) OK - Expected (FALSE) Returned (FALSE)\n");
	else
		printf("ft_calcul_left :( KO - Expected (FALSE) Returned (TRUE)\n");

	if (ft_calcul_left(grid, 4, 2, 2) == true)
		printf("ft_calcul_left :) OK - Expected (TRUE) Returned (TRUE)\n");
	else
		printf("ft_calcul_left :( KO - Expected (TRUE) Returned (FALSE)\n");

	if (ft_calcul_left(grid, 4, 3, 2) == false)
		printf("ft_calcul_left :) OK - Expected (FALSE) Returned (FALSE)\n");
	else
		printf("ft_calcul_left :( KO - Expected (FALSE) Returned (TRUE)\n");

	ft_free_grid(grid);
}

void	test_calcul_right(void)
{
	int **grid = ft_create_grid();
	
	if (ft_calcul_right(grid, 4, 1, 0) == true)
		printf("ft_calcul_right :) OK - Expected (TRUE) Returned (TRUE)\n");
	else
		printf("ft_calcul_right :( KO - Expected (TRUE) Returned (FALSE)\n");

	if (ft_calcul_right(grid, 4, 3, 0) == false)
		printf("ft_calcul_right :) OK - Expected (FALSE) Returned (FALSE)\n");
	else
		printf("ft_calcul_right :( KO - Expected (FALSE) Returned (TRUE)\n");

	if (ft_calcul_right(grid, 4, 2, 2) == true)
		printf("ft_calcul_right :) OK - Expected (TRUE) Returned (TRUE)\n");
	else
		printf("ft_calcul_right :( KO - Expected (TRUE) Returned (FALSE)\n");

	if (ft_calcul_right(grid, 4, 1, 2) == false)
		printf("ft_calcul_right :) OK - Expected (FALSE) Returned (FALSE)\n");
	else
		printf("ft_calcul_right :( KO - Expected (FALSE) Returned (TRUE)\n");

	ft_free_grid(grid);
}

void	test_calcul_up(void)
{
	int **grid = ft_create_grid();
	int exp_up[] = {4, 3, 2, 1};
	int exp_up_false[] = {1, 4, 3, 2};
	
	if (ft_calcul_up(grid, 4, exp_up, 0) == true)
		printf("ft_calcul_up :) OK - Expected (TRUE) Returned (TRUE)\n");
	else
		printf("ft_calcul_up :( KO - Expected (TRUE) Returned (FALSE)\n");

	if (ft_calcul_up(grid, 4, exp_up_false, 0) == false)
		printf("ft_calcul_up :) OK - Expected (FALSE) Returned (FALSE)\n");
	else
		printf("ft_calcul_up :( KO - Expected (FALSE) Returned (TRUE)\n");

	if (ft_calcul_up(grid, 4, exp_up, 2) == true)
		printf("ft_calcul_up :) OK - Expected (TRUE) Returned (TRUE)\n");
	else
		printf("ft_calcul_up :( KO - Expected (TRUE) Returned (FALSE)\n");

	if (ft_calcul_up(grid, 4, exp_up_false, 2) == false)
		printf("ft_calcul_up :) OK - Expected (FALSE) Returned (FALSE)\n");
	else
		printf("ft_calcul_up :( KO - Expected (FALSE) Returned (TRUE)\n");

	free(grid);
}

void	test_calcul_up_c(void)
{
	int **grid = ft_create_grid();
	int exp_up[] = {4, 3, 2, 1};
	int exp_up_false[] = {1, 4, 3, 2};
	
	if (ft_calcul_up_c(grid, 4, exp_up, 0) == true)
		printf("ft_calcul_up :) OK - Expected (TRUE) Returned (TRUE)\n");
	else
		printf("ft_calcul_up :( KO - Expected (TRUE) Returned (FALSE)\n");

	if (ft_calcul_up_c(grid, 4, exp_up_false, 0) == false)
		printf("ft_calcul_up :) OK - Expected (FALSE) Returned (FALSE)\n");
	else
		printf("ft_calcul_up :( KO - Expected (FALSE) Returned (TRUE)\n");

	if (ft_calcul_up_c(grid, 4, exp_up, 2) == true)
		printf("ft_calcul_up :) OK - Expected (TRUE) Returned (TRUE)\n");
	else
		printf("ft_calcul_up :( KO - Expected (TRUE) Returned (FALSE)\n");

	if (ft_calcul_up_c(grid, 4, exp_up_false, 2) == false)
		printf("ft_calcul_up :) OK - Expected (FALSE) Returned (FALSE)\n");
	else
		printf("ft_calcul_up :( KO - Expected (FALSE) Returned (TRUE)\n");

	free(grid);
}

int	main(void)
{
/* 	test_factorial();
	printf("\n");
	test_calcul_left();
	printf("\n");
	test_calcul_right();
	printf("\n");
	test_calcul_up_c(); */
	test_calcul_up();
}