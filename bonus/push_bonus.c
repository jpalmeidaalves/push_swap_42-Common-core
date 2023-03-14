/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:26:35 by joaoalme          #+#    #+#             */
/*   Updated: 2023/03/14 19:44:56 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	push(t_element **s_from, t_element **s_to)
{
	t_element	*head_from;
	t_element	*head_to;
	t_element	*tmp;

	head_from = *s_from;
	head_to = *s_to;
	tmp = head_from;
	head_from = head_from->next;
	*s_from = head_from;
	if (!head_to)
	{
		head_to = tmp;
		head_to->next = NULL;
		*s_to = head_to;
	}
	else
	{
		tmp->next = head_to;
		*s_to = tmp;
	}
}

void	pa(t_element **stack_a, t_element **stack_b)
{
	push(stack_b, stack_a);
	ft_printf("pa\n");
}

void	pb(t_element **stack_a, t_element **stack_b)
{
	push(stack_a, stack_b);
	ft_printf("pb\n");
}
/*
int	main(int ac, char **av)
{
	
	t_element	*head_a;
	t_element	*head_b;
	
	head_a = create_stacks(ac, av);
	head_b = NULL;
	printf("stack a:\n");
	ft_print_list(head_a);

	push_element(&head_a, &head_b);
	printf("stack b:\n");
	ft_print_list(head_b);
	printf("stack a:\n");
	ft_print_list(head_a);

}*/
