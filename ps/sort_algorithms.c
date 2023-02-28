/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithms.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 12:46:52 by joaoalme          #+#    #+#             */
/*   Updated: 2023/02/28 20:13:45 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	hard_3(t_element **stack)
{
	t_element	*curr;

	curr = *stack;
	if (!is_sorted(stack))
	{
		if (curr->nb == f_min(&curr))
		{
			sa(stack);
			ra(stack);
		}
		else if (curr->nb == f_max(&curr)
			&& curr->next->nb != f_min(&curr))
		{
			sa(stack);
			rra(stack);
		}
		else if (curr->nb == f_max(&curr)
			&& curr->next->nb == f_min(&curr))
			ra(stack);
		else if (curr->next->nb == f_min(&curr)
			&& curr->nb != f_max(&curr))
			sa(stack);
		else
			rra(stack);
	}
}

void	simple_sort(t_element **stack_a, t_element **stack_b)
{
	int	min;

	while (f_size_l(stack_a) > 3)
	{
		min = f_min(stack_a);
		if (f_distance(*stack_a, min) <= f_size_l(stack_a) / 2)
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
	while (f_size_l(stack_b) > 0)
		pa(stack_a, stack_b);
}

void	sort_big(t_element **stack_a, t_element **stack_b)
{
//	t_element	*s_b;
	int			i;
	
//	s_b = *stack_b;
	*stack_b = sorting_b(stack_a);
	*stack_a = sorting_a(stack_a, stack_b);
	i = f_distance(*stack_a, f_min(stack_a));
	if (i < f_size_l(stack_a) - i)
	{	
		while((*stack_a)->nb != f_min(stack_a))
			ra(stack_a);
	}
	else
	{
		while ((*stack_a)->nb != f_min(stack_a))
			rra(stack_a);
	}
	
}

/*
void	hard_3_rev(t_element **stack)
{
	t_element	*curr;
	int			min;
	int			max;

	curr = *stack;
	min = search_low(&curr);
	max = search_high(&curr);
	if (!is_sorted(stack))
	{
		if (curr->nb == min && curr->next->nb != max)
		{
			sb(stack);
			rrb(stack);
		}
		else if (curr->nb == min && curr->next->nb == max)
			rb(stack);
		else if (curr->nb == max && curr->next->nb == min)
		{
			sb(stack);
			rb(stack);
		}
		else if (curr->next->nb == max && curr->nb != min)
			sb(stack);
		else if (curr->next->nb == min && curr->nb != max)
			rrb(stack);
	}
}
*/
/*
void	algo_big(t_element **stack_a, t_element **stack_b)
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

int	find_index(t_element **stack, int nb)
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
