/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort_big.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:54:45 by joaoalme          #+#    #+#             */
/*   Updated: 2023/02/28 19:55:25 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_b_3(t_element **s_a, t_element **s_b) //ft_sort_b_till_3
{
	int i;
	t_element *curr;

	while (f_size_l(s_a) > 3 && !is_sorted(s_a))
	{
		curr = *s_a;
		i = find_out_move_ab(*s_a, *s_b);
		while (i >= 0)
		{
			if (i == f_rarb(*s_a, *s_b, curr->nb))
				i = apply_rarb(s_a, s_b, curr->nb, 'a');
			else if (i == f_rrarrb(*s_a, *s_b, curr->nb))
				i = apply_rrarrb(s_a, s_b, curr->nb, 'a');
			else if (i == f_rarrb(*s_a, *s_b, curr->nb))
				i = apply_rarrb(s_a, s_b, curr->nb, 'a');
			else if (i == f_rrarb_a(*s_a, *s_b, curr->nb))
				i = apply_rrarb(s_a, s_b, curr->nb, 'a');
			else
				curr = curr->next;
		}
	}
}

t_element	*sorting_b(t_element **s_a)
{
	t_element	*s_b;

	s_b = NULL;
	if (f_size_l(s_a) > 3 && !is_sorted(s_a))
		pb(s_a, &s_b);
	if (f_size_l(s_a) > 3 && !is_sorted(s_a))
		pb(s_a, &s_b);
	if (f_size_l(s_a) > 3 && !is_sorted(s_a))
		sort_b_3(s_a, &s_b);
	if (!is_sorted(s_a))
		hard_3(s_a);
	return (s_b);
}

t_element	*sorting_a(t_element **s_a, t_element **s_b)
{
	int			i;
	t_element	*curr;
	t_element	*h_a;

	h_a = *s_a;
	while (*s_b)
	{
		curr = *s_b;
		i = find_out_move_ba(*s_a, *s_b);
		 while (i >= 0)
		{
			if (i == f_rarb_a(*s_a, *s_b, curr->nb))
				i = apply_rarb(s_a, s_b, curr->nb, 'b');
			else if (i == f_rarrb_a(*s_a, *s_b, curr->nb))
				i = apply_rarrb(s_a, s_b, curr->nb, 'b');
			else if (i == f_rrarrb_a(*s_a, *s_b, curr->nb))
				i = apply_rrarrb(s_a, s_b, curr->nb, 'b');
			else if (i == f_rrarb_a(*s_a, *s_b, curr->nb))
				i = apply_rrarb(s_a, s_b, curr->nb, 'b');
			else
				curr = curr->next;
		}
	}
	s_a =&h_a;
	return (*s_a);
}

int	find_out_move_ab(t_element *a, t_element *b)
{
	int			i;
	t_element	*tmp;

	tmp = a;
	i = f_rrarrb(a, b, a->nb);
	while (tmp)
	{
		if (i > f_rarb(a, b, tmp->nb))
			i = f_rarb(a, b, tmp->nb);
		if (i > f_rrarrb(a, b, tmp->nb))
			i = f_rrarrb(a, b, tmp->nb);
		if (i > f_rarrb(a, b, tmp->nb))
			i = f_rarrb(a, b, tmp->nb);
		if (i > f_rrarb(a, b, tmp->nb))
			i = f_rrarb(a, b, tmp->nb);
		tmp = tmp->next;
	}
	return (i);
}

int     find_out_move_ba(t_element *a, t_element *b)
{
        int                     i;
        t_element       *tmp;

        tmp = b;
        i = f_rrarrb_a(a, b, b->nb);
        while (tmp)
        {
                if (i > f_rarb_a(a, b, tmp->nb))
                        i = f_rarb_a(a, b, tmp->nb);
                if (i > f_rrarrb_a(a, b, tmp->nb))
                        i = f_rrarrb_a(a, b, tmp->nb);
                if (i > f_rarrb_a(a, b, tmp->nb))
                        i = f_rarrb_a(a, b, tmp->nb);
                if (i > f_rrarb_a(a, b, tmp->nb))
                        i = f_rrarb_a(a, b, tmp->nb);
                tmp = tmp->next;
        }
        return (i);
}



int	f_position_in_b(t_element **stack, int nb)
{
	int			pos;
	t_element	*tmp;

	pos = 1;
	if (nb > (*stack)->nb && nb < find_tail(stack)->nb)
		pos = 0;
	else if (nb > f_max(stack) || nb < f_min(stack))
		pos = f_distance(*stack, f_max(stack));
	else
	{
		tmp = (*stack)->next;
		while ((*stack)->nb < nb || tmp->nb > nb)
		{
			*stack = (*stack)->next;
			tmp = (*stack)->next;
			pos++;
		}
	}
	return (pos);
}

int	f_position_in_a(t_element **stack, int nb)
{
	int			pos;
	t_element	*tmp;

	pos = 1;
	if (nb < (*stack)->nb && nb > find_tail(stack)->nb)
		pos = 0;
	else if (nb > f_max(stack) || nb < f_min(stack))
		pos = f_distance(*stack, f_min(stack));
	else
	{
		tmp = (*stack)->next;
		while ((*stack)->nb > nb || tmp->nb < nb)
		{
			*stack = (*stack)->next;
			tmp = (*stack)->next;
			pos++;
		}
	}
	return (pos);
}
