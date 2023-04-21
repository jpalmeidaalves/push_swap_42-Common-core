/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:26:13 by joaoalme          #+#    #+#             */
/*   Updated: 2023/04/21 15:25:18 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

int	rotate(t_element **stack)
{
	t_element	*head;
	t_element	*tail;

	if (f_size_l(stack) < 2)
		return (1);
	head = *stack;
	tail = find_tail(&head);
	*stack = head->next;
	head->next = NULL;
	tail->next = head;
	return (0);
}

int	ra(t_element **stack_a)
{
	if (rotate(stack_a) == 1)
		return (1);
	ft_printf("ra\n");
	return (0);
}

int	rb(t_element **stack_b)
{
	if (rotate(stack_b) == 1)
		return (1);
	ft_printf("rb\n");
	return (0);
}

int	rr(t_element **stack_a, t_element **stack_b)
{
	if (rotate(stack_a) == 1)
		return (1);
	if (rotate(stack_b) == 1)
		return (1);
	ft_printf("rr\n");
	return (0);
}

/*
int	main(int ac, char **av)
{
	t_element	**stack_a;
	
	stack_a = malloc(sizeof(t_element));
	*stack_a = create_stack(ac, av);
	printf("stack a:\n");
	ft_print_list(stack_a);

	
	ra(stack_a);
	printf("stack a:\n");
	ft_print_list(stack_a);
	
	ra(stack_a);
	printf("stack a:\n");
	ft_print_list(stack_a);


	ra(stack_a);
	printf("stack a:\n");
	ft_print_list(stack_a);

	ra(stack_a);
	printf("stack a:\n");
	ft_print_list(stack_a);

	return (0);	
}*/
