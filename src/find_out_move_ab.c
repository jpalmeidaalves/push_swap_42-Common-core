/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_out_move_ab.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 19:24:17 by joaoalme          #+#    #+#             */
/*   Updated: 2023/03/02 19:55:28 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_out_move_ab(t_element *a, t_element *b)
{
	int			i;
	t_element	*tmp;

	tmp = a;
	i = f_rrarrb(a, b, a->nb);
	while (tmp)
	{
		if (f_rarb(a, b, tmp->nb) < i)
			i = f_rarb(a, b, tmp->nb);
		if (f_rrarrb(a, b, tmp->nb) < i)
			i = f_rrarrb(a, b, tmp->nb);
		if (f_rarrb(a, b, tmp->nb) < i)
			i = f_rarrb(a, b, tmp->nb);
		if (f_rrarb(a, b, tmp->nb) < i)
			i = f_rrarb(a, b, tmp->nb);
		tmp = tmp->next;
	}
	return (i);
}

int	f_rrarrb(t_element *a, t_element *b, int nb)
{
	int	movs;

	movs = 0;
	if (f_position_in_b(&b, nb))
		movs = f_size_l(&b) - f_position_in_b(&b, nb);
	if (((f_size_l(&a) - f_distance(a, nb)) > movs) && f_distance(a, nb))
		movs = f_size_l(&a) - f_distance(a, nb);
	return (movs);
}

int	f_rarb(t_element *a, t_element *b, int nb)
{
	int	movs;

	movs = f_position_in_b(&b, nb);
	if (f_distance(a, nb) > movs)
		movs = f_distance(a, nb);
	return (movs);
}

int	f_rrarb(t_element *a, t_element *b, int nb)
{
	int	movs;

	movs = 0;
	if (f_distance(a, nb))
		movs = f_size_l(&a) - f_distance(a, nb);
	movs += f_position_in_b(&b, nb);
	return (movs);
}

int	f_rarrb(t_element *a, t_element *b, int nb)
{
	int	movs;

	movs = 0;
	if (f_position_in_b(&b, nb))
		movs = f_size_l(&b) - f_position_in_b(&b, nb);
	movs += f_distance(a, nb);
	return (movs);
}
