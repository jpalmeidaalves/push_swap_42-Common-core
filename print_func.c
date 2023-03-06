/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:05:39 by joaoalme          #+#    #+#             */
/*   Updated: 2023/02/24 16:05:44 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_list(t_element **stack)
{
	t_element	*head;

	head = *stack;
	while (head != NULL)
	{
		ft_printf("%d\n", head->nb);
		head = head->next;
	}
}

void	ft_print_stacks(t_element **stack_a, t_element **stack_b)
{
	t_element	*head_a;
	t_element	*head_b;

	head_a = *stack_a;
	head_b = *stack_b;
	ft_printf("stack a:\n");
	while (head_a != NULL)
	{
		ft_printf("%d \n", head_a->nb);
		head_a = head_a->next;
	}
	ft_printf("---------------\n");
	ft_printf("stack b:\n");
	if (head_b != NULL)
	{
		while (head_b != NULL)
		{
			ft_printf("%d \n", head_b->nb);
			head_b = head_b->next;
		}
	}
	ft_printf("---------------\n");
}
