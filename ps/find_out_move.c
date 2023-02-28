/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_out_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 19:24:17 by joaoalme          #+#    #+#             */
/*   Updated: 2023/02/28 20:15:31 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	f_rrarrb(t_element *a, t_element *b, int nb)
{
	int	i;

	i = 0;
	if (f_position_in_b(&b, nb))
		i = f_size_l(&b) - f_position_in_b(&b, nb);
	if ((i < (f_size_l(&a) - f_distance(a, nb))) && f_distance(a, nb))
		i = f_size_l(&a) - f_distance(a, nb);
	return (i);
}

int     f_rrarrb_a(t_element *a, t_element *b, int nb)
{
        int     i;

        i = 0;
        if (f_position_in_a(&a, nb))
                i = f_size_l(&a) - f_position_in_a(&a, nb);
        if ((i < (f_size_l(&b) - f_distance(b, nb))) && f_distance(b, nb))
                i = f_size_l(&b) - f_distance(b, nb);
        return (i);
}


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

int	f_rarb(t_element *a, t_element *b, int nb)
{
	int	i;

	i = f_position_in_b(&b, nb);
	if (i < f_distance(a, nb))
		i = f_distance(a, nb);
	return (i);
}

int     f_rarb_a(t_element *a, t_element *b, int nb)
{
        int     i;

        i = f_position_in_a(&a, nb);
        if (i < f_distance(b, nb))
                i = f_distance(b, nb);
        return (i);
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

int	f_rrarb(t_element *a, t_element *b, int nb)
{
	int	i;

	i = 0;
	if (f_distance(a, nb))
		i = f_size_l(&a) - f_distance(a, nb);
	i += f_position_in_b(&b, nb);
	return (i);
}

int     f_rrarb_a(t_element *a, t_element *b, int nb)
{
        int     i;

        i = 0;
        if (f_position_in_a(&a, nb))
                i = f_size_l(&a) - f_position_in_a(&a, nb);
        i += f_distance(b, nb);
        return (i);
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

int	f_rarrb(t_element *a, t_element *b, int nb)
{
	int	i;

	i = 0;
	if (f_position_in_b(&b, nb))
		i = f_size_l(&b) - f_position_in_b(&b, nb);
	i = f_distance(a, nb) + i;
	return (i);
}

int     f_rarrb_a(t_element *a, t_element *b, int nb)
{
        int     i;

        i = 0;
        if (f_distance(b, nb))
                i = f_size_l(&b) - f_distance(b, nb);
        i += f_position_in_a(&a, nb);
        return (i);
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
