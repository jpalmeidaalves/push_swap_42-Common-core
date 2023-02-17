/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithms.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 12:46:52 by joaoalme          #+#    #+#             */
/*   Updated: 2023/02/16 20:45:28 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	search_low_ind(t_element **stack)
{
	int			min;
	t_element	*curr;

	curr = *stack;
	min = search_high(stack); 
	while (curr != NULL)
	{
		if (curr->nb < min && curr->index == -1)
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
	if (!is_sorted(stack))
	{
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
}
/*
void    algo_big(t_element **stack_a, t_element **stack_b)
{       
        int                     min;

        while   (ft_size_list(stack_a) > 3)
        {
                min = search_low(stack_a);
                if (find_index(stack_a, min) < ft_size_list(stack_a) / 2)
                {
                        while ((*stack_a)->nb != min)
                                ra(stack_a);
                }
                else    
                        while ((*stack_a)->nb != min)
                                rra(stack_a);
                pb(stack_a, stack_b);
        }       
                hard_3(stack_a);
                while (ft_size_list(stack_b) > 0)
                        pa(stack_a, stack_b);
}

int     find_index(t_element **stack, int nb)
{
        t_element       *curr;
        int                     index;

        curr = *stack;
        index = 0;
        while (curr->nb != nb)
        {
                curr = curr->next;
                index++;
        }
        return (index);
}
*/
