/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 20:10:24 by joaoalme          #+#    #+#             */
/*   Updated: 2023/02/24 19:10:22 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_element	*creat_node(int nb)
{
	t_element	*new_elm;

	new_elm = malloc(sizeof(t_element));
	if (!new_elm)
		exit(EXIT_FAILURE);
	new_elm->nb = nb;
	new_elm->next = 0;
	new_elm->index = -1;
	return (new_elm);
}

t_element	*find_tail(t_element **stack)
{
	t_element	*tail;

	tail = *stack;
	while (tail->next != NULL)
		tail = tail->next;
	return (tail);
}

t_element	*add_element_back(int nb, t_element **head)
{
	t_element	*new_node;
	t_element	*tail;

	tail = find_tail(head);
	new_node = creat_node(nb);
	tail->next = new_node;
	new_node->prev = tail;
	return (new_node);
}

void	ft_set_ind(t_element **stack, int min, int ind)
{
	t_element	*curr;

	curr = *stack;
	while (curr != NULL)
	{
		if (curr->nb == min)
		{
			curr->index = ind;
			return ;
		}
		curr = curr->next;
	}
}
/*
void	ft_indexing(t_element **stack)
{
	int	ind;
	int	min;

	ind = 0;
	while (ind < f_size_l(stack))
	{
		min = f_min_ind(stack);
		ft_set_ind(stack, min, ind);
		ind++;
	}
}*/
