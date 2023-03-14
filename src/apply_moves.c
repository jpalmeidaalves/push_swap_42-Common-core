/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:02:58 by joaoalme          #+#    #+#             */
/*   Updated: 2023/03/02 19:03:02 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	apply_rrarrb(t_element **a, t_element **b, int nb, char s)
{
	if (s == 'a')
	{
		while ((*a)->nb != nb && f_position_in_b(b, nb) > 0)
			rrr(a, b);
		while ((*a)->nb != nb)
			rra(a);
		while (f_position_in_b(b, nb) > 0)
			rrb(b);
		pb(a, b);
	}
	else
	{
		while ((*b)->nb != nb && f_position_in_a(a, nb) > 0)
			rrr(a, b);
		while ((*b)->nb != nb)
			rrb(b);
		while (f_position_in_a(a, nb) > 0)
			rra(a);
		pa(a, b);
	}
	return (-1);
}

int	apply_rarb(t_element **a, t_element **b, int nb, char s)
{
	if (s == 'a')
	{
		while ((*a)->nb != nb && f_position_in_b(b, nb) > 0)
			rr(a, b);
		while ((*a)->nb != nb)
			ra(a);
		while (f_position_in_b(b, nb) > 0)
			rb(b);
		pb(a, b);
	}
	else
	{
		while ((*b)->nb != nb && f_position_in_a(a, nb) > 0)
			rr(a, b);
		while ((*b)->nb != nb)
			rb(b);
		while (f_position_in_a(a, nb) > 0)
			ra(a);
		pa(a, b);
	}
	return (-1);
}

int	apply_rrarb(t_element **a, t_element **b, int nb, char s)
{
	if (s == 'a')
	{
		while ((*a)->nb != nb)
			rra(a);
		while (f_position_in_b(b, nb) > 0)
			rb(b);
		pb(a, b);
	}
	else
	{
		while (f_position_in_a(a, nb) > 0)
			rra(a);
		while ((*b)->nb != nb)
			rb(b);
		pa(a, b);
	}
	return (-1);
}

int	apply_rarrb(t_element **a, t_element **b, int nb, char s)
{
	if (s == 'a')
	{
		while ((*a)->nb != nb)
			ra(a);
		while (f_position_in_b(b, nb) > 0)
			rrb(b);
		pb(a, b);
	}
	else
	{
		while (f_position_in_a(a, nb) > 0)
			ra(a);
		while ((*b)->nb != nb)
			rrb(b);
		pa(a, b);
	}
	return (-1);
}
