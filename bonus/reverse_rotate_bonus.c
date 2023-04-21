/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:51:44 by joaoalme          #+#    #+#             */
/*   Updated: 2023/04/21 15:24:39 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

int	rev_rot(t_element **stack)
{
	t_element	*head;
	t_element	*tail;

	if (f_size_l(stack) < 2)
		return (1);
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
	return (0);
}

int	rra(t_element **stack_a)
{
	if (rev_rot(stack_a) == 1)
		return (1);
	ft_printf("rra\n");
	return (0);
}

int	rrb(t_element **stack_b)
{
	if (rev_rot(stack_b) == 1)
		return (1);
	ft_printf("rrb\n");
	return (0);
}

int	rrr(t_element **stack_a, t_element **stack_b)
{
	if (rev_rot(stack_a) == 1)
		return (1);
	if (rev_rot(stack_b) == 1)
		return (1);
	ft_printf("rrr\n");
	return (0);
}
