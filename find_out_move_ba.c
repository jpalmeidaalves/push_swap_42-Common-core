/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_out_move_ba.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 19:24:17 by joaoalme          #+#    #+#             */
/*   Updated: 2023/03/02 19:55:05 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_out_move_ba(t_element *a, t_element *b)
{
	int			i;
	t_element	*tmp;

	tmp = b;
	i = f_rrarrb_a(a, b, b->nb);
	while (tmp)
	{
		if (f_rarb_a(a, b, tmp->nb) < i)
			i = f_rarb_a(a, b, tmp->nb);
		if (f_rrarrb_a(a, b, tmp->nb) < i)
			i = f_rrarrb_a(a, b, tmp->nb);
		if (f_rarrb_a(a, b, tmp->nb) < i)
			i = f_rarrb_a(a, b, tmp->nb);
		if (f_rrarb_a(a, b, tmp->nb) < i)
			i = f_rrarb_a(a, b, tmp->nb);
		tmp = tmp->next;
	}
	return (i);
}

int	f_rrarrb_a(t_element *a, t_element *b, int nb)
{
	int	movs;

	movs = 0;
	if (f_position_in_a(&a, nb))
		movs = f_size_l(&a) - f_position_in_a(&a, nb);
	if (((f_size_l(&b) - f_distance(b, nb)) > movs) && f_distance(b, nb))
		movs = f_size_l(&b) - f_distance(b, nb);
	return (movs);
}

int	f_rarb_a(t_element *a, t_element *b, int nb)
{
	int	movs;

	movs = f_position_in_a(&a, nb);
	if (movs < f_distance(b, nb))
		movs = f_distance(b, nb);
	return (movs);
}

int	f_rrarb_a(t_element *a, t_element *b, int nb)
{
	int	movs;

	movs = 0;
	if (f_position_in_a(&a, nb))
		movs = f_size_l(&a) - f_position_in_a(&a, nb);
	movs += f_distance(b, nb);
	return (movs);
}

int	f_rarrb_a(t_element *a, t_element *b, int nb)
{
	int	movs;

	movs = 0;
	if (f_distance(b, nb))
		movs = f_size_l(&b) - f_distance(b, nb);
	movs += f_position_in_a(&a, nb);
	return (movs);
}
