/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:19:53 by joaoalme          #+#    #+#             */
/*   Updated: 2023/02/24 19:09:33 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     is_sorted(t_element **stack)
{
        int                     sort;
        t_element       *current;

        sort = 1;
        current = *stack;
        while (current->next != NULL)
        {
                if (current->nb > current->next->nb)
                {
                        sort = 0;
                        return (sort);
                }
                current = current->next;
        }
        return (sort);
}

int	f_min(t_element **stack)
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

int     f_distance(t_element *stack, int nb)
{
        t_element       *curr;
        int                     dist;

        curr = stack;
        dist = 0;
        while (stack->nb != nb)
        {
                stack = stack->next;
                dist++;
        }
        stack = curr;
        return (dist);
}
/*
int	f_min_ind(t_element **stack)
{
	int			min;
	t_element	*curr;

	curr = *stack;
	min = f_max(stack);
	while (curr != NULL)
	{
		if (curr->nb < min && curr->index == -1)
			min = curr->nb;
		curr = curr->next;
	}
	return (min);
}
*/
int	f_max(t_element **stack)
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

int	f_size_l(t_element **stack)
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
