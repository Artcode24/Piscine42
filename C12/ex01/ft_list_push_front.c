/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 02:24:42 by arthur            #+#    #+#             */
/*   Updated: 2025/01/06 02:26:05 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *new_element;

	new_element = malloc(sizeof(t_list));

	new_element->data = data;
	new_element->next = *begin_list;
	*begin_list = new_element;
}

#include <stdio.h>

int	main(void)
{
	t_list *head;

	int	a = 42;
	int	b = 24;

	head = NULL;
	
	ft_list_push_front(&head, &a);
	ft_list_push_front(&head, &b);

	t_list *ptr = head;
	while (ptr)
	{
		printf("%d", *(int *)ptr->data);
		printf("\n");
		ptr = ptr->next;
	}
}