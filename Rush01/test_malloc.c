int **array = malloc(rows * sizeof(int *)); // Allouer un tableau de pointeurs

    for (int i = 0; i < rows; i++) 
    {    
	array[i] = malloc(cols * sizeof(int)); // Allouer chaque ligne
    }