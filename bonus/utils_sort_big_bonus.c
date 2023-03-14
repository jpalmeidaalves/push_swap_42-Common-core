/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort_big_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:54:45 by joaoalme          #+#    #+#             */
/*   Updated: 2023/03/14 19:46:14 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	sort_b_3(t_element **sa, t_element **sb)
{
	int			i;
	t_element	*curr;

	while (f_size_l(sa) > 3 && !is_sorted(sa))
	{
		curr = *sa;
		i = find_out_move_ab(*sa, *sb);
		while (i >= 0)
		{
			if (i == f_rarb(*sa, *sb, curr->nb))
				i = apply_rarb(sa, sb, curr->nb, 'a');
			else if (i == f_rrarrb(*sa, *sb, curr->nb))
				i = apply_rrarrb(sa, sb, curr->nb, 'a');
			else if (i == f_rarrb(*sa, *sb, curr->nb))
				i = apply_rarrb(sa, sb, curr->nb, 'a');
			else if (i == f_rrarb(*sa, *sb, curr->nb))
				i = apply_rrarb(sa, sb, curr->nb, 'a');
			else
				curr = curr->next;
		}
	}
}

t_element	*sorting_b(t_element **sa)
{
	t_element	*sb;

	sb = NULL;
	if (f_size_l(sa) > 3 && !is_sorted(sa))
		pb(sa, &sb);
	if (f_size_l(sa) > 3 && !is_sorted(sa))
		pb(sa, &sb);
	if (f_size_l(sa) > 3 && !is_sorted(sa))
		sort_b_3(sa, &sb);
	if (!is_sorted(sa))
		hard_3(sa);
	return (sb);
}

t_element	*sorting_a(t_element **sa, t_element **sb)
{
	int			i;
	t_element	*curr;

	while (*sb)
	{
		curr = *sb;
		i = find_out_move_ba(*sa, *sb);
		while (i >= 0)
		{
			if (i == f_rarb_a(*sa, *sb, curr->nb))
				i = apply_rarb(sa, sb, curr->nb, 'b');
			else if (i == f_rarrb_a(*sa, *sb, curr->nb))
				i = apply_rarrb(sa, sb, curr->nb, 'b');
			else if (i == f_rrarrb_a(*sa, *sb, curr->nb))
				i = apply_rrarrb(sa, sb, curr->nb, 'b');
			else if (i == f_rrarb_a(*sa, *sb, curr->nb))
				i = apply_rrarb(sa, sb, curr->nb, 'b');
			else
				curr = curr->next;
		}
	}
	return (*sa);
}

int	f_position_in_b(t_element **s, int nb)
{
	int			pos;
	t_element	*tmp;
	t_element	*head;

	head = *s;
	pos = 1;
	if (nb > (*s)->nb && nb < find_tail(s)->nb)
		pos = 0;
	else if (nb > f_max(s) || nb < f_min(s))
		pos = f_distance(*s, f_max(s));
	else
	{
		tmp = (*s)->next;
		while ((*s)->nb < nb || tmp->nb > nb)
		{
			*s = (*s)->next;
			tmp = (*s)->next;
			pos++;
		}
	}
	*s = head;
	return (pos);
}

int	f_position_in_a(t_element **s, int nb)
{
	int			pos;
	t_element	*tmp;
	t_element	*head;

	pos = 1;
	head = *s;
	if (nb < (*s)->nb && nb > find_tail(s)->nb)
		pos = 0;
	else if (nb > f_max(s) || nb < f_min(s))
		pos = f_distance(*s, f_min(s));
	else
	{
		tmp = (*s)->next;
		while ((*s)->nb > nb || tmp->nb < nb)
		{
			*s = (*s)->next;
			tmp = (*s)->next;
			pos++;
		}
	}
	*s = head;
	return (pos);
}
