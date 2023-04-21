/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 20:10:27 by joaoalme          #+#    #+#             */
/*   Updated: 2023/04/21 15:25:35 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

int	swap(t_element **stack)
{
	t_element	*head;
	int			temp_nb;

	if (f_size_l(stack) < 2)
		return (1);
	head = *stack;
	temp_nb = head->nb;
	head->nb = head->next->nb;
	head->next->nb = temp_nb;
	return (0);
}

int	sa(t_element **stack_a)
{
	if (swap(stack_a) == 1)
		return (1);
	ft_printf("sa\n");
	return (0);
}

int	sb(t_element **stack_b)
{
	if (swap(stack_b) == 1)
		return (1);
	ft_printf("sb\n");
	return (0);
}

int	ss(t_element **stack_a, t_element **stack_b)
{
	if (swap(stack_a) == 1)
		return (1);
	if (swap(stack_b) == 1)
		return (1);
	ft_printf("ss\n");
	return (0);
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
