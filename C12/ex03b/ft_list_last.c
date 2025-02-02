/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:41:04 by arthur            #+#    #+#             */
/*   Updated: 2025/01/09 17:17:09 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "ft_list.h"

t_list	*ft_create_element(void *data)
{
	t_list	*elem;

	elem = malloc(sizeof(t_list));
	if (!elem)
		return (NULL);
	
	elem->data = data;
	elem->next = NULL;

	return (elem);
}

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *new_element;

	new_element = ft_create_element(data);

	new_element->next = *begin_list;
	*begin_list = new_element;
}

t_list	*ft_list_last(t_list *begin_list)
{
	t_list	*ptr;

	ptr = begin_list;

	while (ptr->next != NULL)
	{
		ptr = ptr->next;
	}

	return (ptr);
}


int	main(void)
{
	t_list *head;
	int	a, b, c;

	a = 42, b = 24, c = 48;

	head = NULL;

	ft_list_push_front(&head, &a);
	ft_list_push_front(&head, &b);
	ft_list_push_front(&head, &c);

	
	t_list *last = ft_list_last(head);
	
	printf("%d", *(int *)last->data);
}