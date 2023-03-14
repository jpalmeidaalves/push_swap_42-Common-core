/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 12:15:15 by joaoalme          #+#    #+#             */
/*   Updated: 2023/03/06 21:26:26 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_stack(t_element **stack_a, t_element **stack_b)
{
	t_element	*temp;

	temp = stack_a[0];
	while (stack_a[0] != NULL)
	{
		temp = stack_a[0];
		stack_a[0] = stack_a[0]->next;
		free(temp);
	}
	free(stack_a);
	free(stack_b);
}

void	sorting(t_element **stack_a, t_element **stack_b, int nb_elem)
{
	nb_elem = f_size_l(stack_a);
	if (nb_elem == 2)
	{
		(void)stack_b;
		sa(stack_a);
	}
	else if (nb_elem == 3)
	{
		(void)stack_b;
		hard_3(stack_a);
	}
	else if (nb_elem <= 10)
		simple_sort(stack_a, stack_b);
	else
		sort_big(stack_a, stack_b);
}

t_element	*create_stack(int ac, char **av, t_element **stack)
{
	t_element	*tail;
	char		**args;
	int			count;

	if (ac == 2)
	{
		count = 1;
		args = ft_split(av[1], ' ');
		*stack = creat_node(ft_atoi(args[0]));
		tail = *stack;
	}
	else
	{
		count = 2;
		args = av;
		*stack = creat_node(ft_atoi(args[1]));
		tail = *stack;
	}
	build_stack(args, tail, count);
	if (ac == 2)
		free_args(args);
	return (*stack);
}
