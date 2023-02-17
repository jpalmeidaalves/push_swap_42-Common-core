/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:51:44 by joaoalme          #+#    #+#             */
/*   Updated: 2023/02/08 18:51:51 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rot(t_element **stack)
{
	t_element	*head;
	t_element	*tail;
	
	head = *stack;
	tail = find_tail(&head);
	while (head)
	{
		if (head->next->next == NULL)
		{
			 head->next = NULL;
			 break ;
		}
		head = head->next;
	}
	tail->next = *stack;
	*stack = tail;
}

void	rra(t_element **stack_a)
{
	rev_rot(stack_a);
	ft_printf("rra\n");
}

void	rrb(t_element **stack_b)
{
	rev_rot(stack_b);
	ft_printf("rrb\n");
}

void	rrr(t_element **stack_a, t_element **stack_b)
{
	rev_rot(stack_a);
	rev_rot(stack_b);
	ft_printf("rrr\n");
}
