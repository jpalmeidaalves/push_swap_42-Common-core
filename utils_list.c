/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 20:10:24 by joaoalme          #+#    #+#             */
/*   Updated: 2023/02/10 16:20:06 by joaoalme         ###   ########.fr       */
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
	return (new_elm);
}

t_element	*find_tail(t_element **stack)
{
	t_element	*tail;
//	t_element	*head;

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

t_element	*add_element_back(int nb, t_element **head)
{
	t_element	*new_node;
	t_element	*tail;

	tail = find_tail(head);
	new_node = creat_node(nb);
	tail->next = new_node;
	return (new_node);
}

void	add_element_front(int nb, t_element **head)
{
	t_element	*new_node;

	new_node = creat_node(nb);
	new_node->next = *head;
	*head = new_node;
}

void	ft_print_list(t_element **stack)
{
	t_element	*head;

	head = *stack;
	while (head != NULL)
	{
		printf("%d\n", head->nb);
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
		printf("%d\n", head_a->nb);
		head_a = head_a->next;
	}
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

