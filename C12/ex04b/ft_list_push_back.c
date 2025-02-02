/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arthur <arthur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 02:05:35 by arthur            #+#    #+#             */
/*   Updated: 2025/01/13 02:06:56 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../ex-/ft_list.h"

void ft_list_push_back(t_list **begin_list, void *data)
{
	t_list *ptr;
	t_list *new_elem;

	ptr = *begin_list;
	new_elem = ft_create_element(data);

	while (ptr->next != NULL)
	{
		ptr = ptr->next;
	}
	
	ptr->next = new_elem;
}