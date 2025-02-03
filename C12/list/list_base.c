/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:41:04 by arthur            #+#    #+#             */
/*   Updated: 2025/02/03 11:54:22 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "ft_list.h"

t_list	*ft_create_element(void *);
void	ft_list_push_front(t_list **, void *);
t_list	*ft_list_last(t_list *);
void	ft_list_push_back(t_list **, void *);
t_list	*ft_list_push_strs(int size, char **strs);



int	main(void)
{
	
}

t_list	*ft_create_element(void *data)
{
	t_list	*new_elem;

	new_elem = (t_list *)malloc(sizeof(t_list));
	if (!new_elem)
		return (NULL);
	
	new_elem->data = data;
	new_elem->next = NULL;

	return (new_elem);
}

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*new_elem;

	new_elem = ft_create_element(data);

	new_elem->next = *begin_list;
	*begin_list = new_elem;
}

int	ft_list_size(t_list *begin_list)
{
	t_list	*ptr;
	int	count;

	ptr = begin_list;
	count = 0;	
	while (ptr)	
	{
		ptr = ptr->next;
		count++;
	}
	return (count);
}

t_list	*ft_list_last(t_list *begin_list)
{
	t_list	*ptr;

	ptr = begin_list;
	while (ptr->next)
		ptr = ptr->next;
	return (ptr);
}

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*new_elem;
	t_list	*ptr;

	new_elem = ft_create_element(data);
	ptr = *begin_list;
	
	while (ptr->next)	
	{
		ptr = ptr->next;
	}
	ptr->next = new_elem;
}

t_list	*ft_list_push_strs(int size, char **strs)
{
	char	*strs[] = {"Hello", "Konnichiwa", "Annyeong", "Nihao"};
	t_list	*begin_list;

	ft_create_element(strs[0])
	// faire une boucle
}