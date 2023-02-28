/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 20:10:27 by joaoalme          #+#    #+#             */
/*   Updated: 2023/02/24 19:09:01 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_element **stack)
{
	t_element	*head;
	int			temp_nb;
	int			temp_ind;

	head = *stack;
	temp_nb = head->nb;
	temp_ind = head->index;
	head->nb = head->next->nb;
	head->index = head->next->index;
	head->next->nb = temp_nb;
	head->next->index = temp_ind;
}

void	sa(t_element **stack_a)
{
	swap(stack_a);
	ft_printf("sa\n");
}

void	sb(t_element **stack_b)
{
	swap(stack_b);
	ft_printf("sb\n");
}

void	ss(t_element **stack_a, t_element **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
}

/*
int	main(int ac, char **av)
{
	t_element	*head_a;

	head_a = create_stacks(ac, av);
	ft_print_list(head_a);
	printf("\n");
	swap(&head_a);
	printf("\n");
	ft_print_list(head_a);
}*/
