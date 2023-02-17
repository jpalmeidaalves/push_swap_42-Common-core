/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 20:10:24 by joaoalme          #+#    #+#             */
/*   Updated: 2023/02/16 20:42:53 by joaoalme         ###   ########.fr       */
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

int	ft_size_list(t_element **stack)
{
	t_element	*head;
	int			count;

	count = 0;
	head = *stack;
	while (head != NULL)
	{
		head = head->next;
		count++;
	}
	return (count);
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
			return;
		}
		curr = curr->next;
	}
}

void	ft_indexing(t_element **stack)
{
	int	ind;
	int	min;
	
	ind = 0;
	while(ind < ft_size_list(stack))
	{
		min = search_low_ind(stack);
		ft_set_ind(stack, min, ind);
		ind++;
	}
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

void	ft_print_list(t_element **stack)
{
	t_element	*head;

	head = *stack;
	while (head != NULL)
	{
		ft_printf("%d\n", head->nb);
		head = head->next;
	}
}

void	ft_print_stacks(t_element **stack_a, t_element **stack_b)
{
	t_element	*head_a;
	t_element	*head_b;

	head_a = *stack_a;
	head_b = *stack_b;
	ft_printf("stack a:\n");
	while (head_a != NULL)
	{
		ft_printf("%d [%d]\n", head_a->nb, head_a->index);
		head_a = head_a->next;
	}
	ft_printf("---------------\n");
	ft_printf("stack b:\n");
	if (head_b != NULL)
	{
		while (head_b != NULL)
		{
			ft_printf("%d\n", head_b->nb);
			head_b = head_b->next;
		}
	}
	ft_printf("---------------\n");
}

