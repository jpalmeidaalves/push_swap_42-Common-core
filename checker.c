/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 21:24:01 by joaoalme          #+#    #+#             */
/*   Updated: 2023/03/06 21:45:14 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_move2(t_element **stack_a, t_element **stack_b, char *line)
{
	if (!(ft_strncmp(line, "rb\n", 3)))
		rotate(stack_b);
	if (!(ft_strncmp(line, "rr\n", 3)))
	{
		rotate(stack_a);
		rotate(stack_b);
	}
	if (!(ft_strncmp(line, "rra\n", 4)))
		rev_rot(stack_a);
	if (!(ft_strncmp(line, "rrb\n", 4)))
		rev_rot(stack_b);
	if (!(ft_strncmp(line, "rrr\n", 4)))
	{
		rev_rot(stack_a);
		rev_rot(stack_b);
	}
}

void	make_move(t_element **stack_a, t_element **stack_b, char *line)
{
	if (!(ft_strncmp(line, "sa\n", 3)))
		swap(stack_a);
	if (!(ft_strncmp(line, "sb\n", 3)))
		swap(stack_b);
	if (!(ft_strncmp(line, "ss\n", 3)))
	{
		swap(stack_a);
		swap(stack_b);
	}
	if (!(ft_strncmp(line, "pa\n", 3)))
		push(stack_b, stack_a);
	if (!(ft_strncmp(line, "pb\n", 3)))
		push(stack_a, stack_b);
	if (!(ft_strncmp(line, "ra\n", 3)))
		rotate(stack_a);
	make_move2(stack_a, stack_b, line);
}

void	final_check(t_element **stack_a)
{
	if (is_sorted(stack_a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	main(int ac, char **av)
{
	t_element	**stack_a;
	t_element	**stack_b;
	char		*line;

	if (ac == 1)
		exit(EXIT_FAILURE);
	ft_validate_args(ac, av);
	stack_a = malloc(sizeof(t_element));
	stack_b = malloc(sizeof(t_element));
	if (!stack_b || !stack_a)
		return (-1);
	*stack_a = create_stack(ac, av, stack_a);
	*stack_b = NULL;
	line = get_next_line(0);
	while (line)
	{
		make_move(stack_a, stack_b, line);
		free(line);
		line = get_next_line(0);
	}
	final_check(stack_a);
	free(line);
	free_stack(stack_a, stack_b);
	return (0);
}
