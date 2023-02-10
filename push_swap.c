/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:27:35 by joaoalme          #+#    #+#             */
/*   Updated: 2023/02/10 16:26:22 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_stack(t_element **stack)
{
	int	i;

	i = 0;
	while (stack[i])
	{
		free(stack[i]);
			i++;
	}
}

int	is_sorted(t_element **stack)
{
	int	sort;
	t_element	*current;
	
	
	sort = 1;
	current = *stack;
	while (current->next != NULL)
	{
		if (current->nb > current->next->nb)
		{
			sort = 0;
			return(sort);
		}
		current = current->next;
	}	
	return (sort);
}

t_element       *create_stack(int ac, char **av, t_element **stack)
{
        t_element       *tail;
	char	**args;
        int                     count;

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
        while (args[count])
        {
                tail = add_element_back(atoi(args[count]), &tail);
                count++;
        }
//	free(tail);
        return (*stack);
}

int	main(int ac, char **av)
{
	t_element	**stack_a;
	t_element	**stack_b;
	
	if (ac == 1)
		return (1);
	ft_validate_args(ac, av);	
	stack_a = malloc(sizeof(t_element));
	stack_b = malloc(sizeof(t_element));
	*stack_a = create_stack(ac, av, stack_a);
	*stack_b = NULL;
	if(is_sorted(stack_a) || ft_size_list(stack_a) == 1)
	{
		ft_free_stack(stack_a);
		free(stack_b);
		return (0);
	}
//	ft_print_stacks(stack_a, stack_b);
	sorting(stack_a, stack_b);
//	ft_print_stacks(stack_a, stack_b);v	
	ft_free_stack(stack_a);
	free(stack_b);
	return (0);
}
