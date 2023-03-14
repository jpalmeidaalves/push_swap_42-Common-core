/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:26:13 by joaoalme          #+#    #+#             */
/*   Updated: 2023/02/24 16:51:27 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate(t_element **stack)
{
	t_element	*head;
	t_element	*tail;

	head = *stack;
	tail = find_tail(&head);
	*stack = head->next;
	head->next = NULL;
	tail->next = head;
}

void	ra(t_element **stack_a)
{
	rotate(stack_a);
	ft_printf("ra\n");
}

void	rb(t_element **stack_b)
{
	rotate(stack_b);
	ft_printf("rb\n");
}

void	rr(t_element **stack_a, t_element **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
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
