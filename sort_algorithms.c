/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithms.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 12:46:52 by joaoalme          #+#    #+#             */
/*   Updated: 2023/02/10 16:29:16 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting(t_element **stack_a, t_element **stack_b)
{
	int	nb_elem;

	nb_elem = ft_size_list(stack_a);
	if (nb_elem == 2)
	{
		(void)stack_b;
		sa(stack_a);
	}
	else if (nb_elem == 3)
	{
		(void)stack_b;
		hard_3(stack_a);
	}
	else if (nb_elem == 4)
		hard_4(stack_a, stack_b);
	else if (nb_elem == 5)
		hard_5(stack_a, stack_b);
}

int	search_low(t_element **stack)
{
	int			min;
	t_element	*curr;

	curr = *stack;
	min = curr->nb;
	while (curr != NULL)
	{
		if (curr->nb < min)
			min = curr->nb;
		curr = curr->next;
	}
	return (min);
}

int	search_high(t_element **stack)
{
	int			max;
	t_element	*curr;

	curr = *stack;
	max = curr->nb;
	while (curr != NULL)
	{
		if (curr->nb > max)
			max = curr->nb;
		curr = curr->next;
	}
	return (max);
}

void	hard_3(t_element **stack)
{
	t_element	*curr;
	int			min;
	int			max;

	curr = *stack;
	min = search_low(&curr);
	max = search_high(&curr);
	if (curr->nb == min)
	{
		sa(stack);
		ra(stack);
	}
	else if (curr->nb == max && curr->next->nb != min)
	{
		sa(stack);
		rra(stack);
	}
	else if (curr->nb == max && curr->next->nb == min)
		ra(stack);
	else if (curr->next->nb == min && curr->nb != max)
		sa(stack);
	else
		rra(stack);
}

void	hard_4(t_element **stack_a, t_element **stack_b)
{
	t_element	*head_a;
	int			min;

	head_a = *stack_a;
	min = search_low(stack_a);
	while (head_a->nb != min)
		ra(&head_a);
	pb(stack_a, stack_b);
	sorting(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	rrr_a_and_pb(t_element **stk_a, t_element **stk_b)
{
	rra(stk_a);
	pb(stk_a, stk_b);
}


void	hard_5(t_element **stack_a, t_element **stack_b)
{
	t_element	*head_a;
	t_element	*tail_a;
	int			min;

	head_a = *stack_a;
	tail_a = find_tail(&head_a);
	min = search_low(stack_a);
	if (min == tail_a->nb)
		rrr_a_and_pb(stack_a, stack_b);
	else
	{
		while (head_a->nb != min)
			ra(stack_a);
		pb(stack_a, stack_b);
	}
	head_a = *stack_a;
	min = search_low(stack_a);
	while (head_a->nb != min)
		ra(&head_a);
	pb(stack_a, stack_b);
	hard_3(stack_a);
	if (is_sorted(stack_b))
		sb(stack_b);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}
