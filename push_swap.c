/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:27:35 by joaoalme          #+#    #+#             */
/*   Updated: 2023/03/06 21:26:44 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_element	**stack_a;
	t_element	**stack_b;

	if (ac == 1)
		exit(EXIT_FAILURE);
	ft_validate_args(ac, av);
	stack_a = malloc(sizeof(t_element));
	if (!stack_a)
		return (-1);
	stack_b = malloc(sizeof(t_element));
	if (!stack_b)
		return (-1);
	*stack_a = create_stack(ac, av, stack_a);
	*stack_b = NULL;
	if (is_sorted(stack_a) || f_size_l(stack_a) == 1)
	{
		free_stack(stack_a, stack_b);
		return (0);
	}
	sorting(stack_a, stack_b, ac - 1);
	free_stack(stack_a, stack_b);
	return (0);
}
