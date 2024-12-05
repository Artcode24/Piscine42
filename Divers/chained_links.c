#include <stdlib.h>

typedef struct node
{
	int 		number;
	struct node 	*next;
} node;


int	main(int argc, char *argv[])
{
	node	*list = NULL;
	int	number;

	for (int i = 1; i < argc; i++)
	{
		number = atoi(argv[i]);
		node *n = malloc(sizeof(node));

		n->number = number;
		n->next = list;
		list = n;
	}
}