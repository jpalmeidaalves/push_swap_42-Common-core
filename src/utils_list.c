/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 20:10:24 by joaoalme          #+#    #+#             */
/*   Updated: 2023/03/06 21:28:13 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_element	*creat_node(int nb)
{
	t_element	*new_elm;

	new_elm = malloc(sizeof(t_element));
	if (!new_elm)
		exit(EXIT_FAILURE);
	new_elm->nb = nb;
	new_elm->next = 0;
	return (new_elm);
}

t_element	*find_tail(t_element **stack)
{
	t_element	*tail;

	tail = *stack;
	while (tail->next != NULL)
		tail = tail->next;
	return (tail);
}

void	build_stack(char **args, t_element *tail, int count)
{
	int	nb;

	while (args[count])
	{
		nb = ft_atoi(args[count]);
		if (!nb)
		{
			ft_printf("Error\n");
			exit(EXIT_FAILURE);
		}
		tail = add_element_back(nb, &tail);
		count++;
	}
}

t_element	*add_element_back(int nb, t_element **head)
{
	t_element	*new_node;
	t_element	*tail;

	tail = find_tail(head);
	new_node = creat_node(nb);
	tail->next = new_node;
	return (new_node);
}

void	free_args(char **arr)
{
	int	count;

	count = 0;
	while (arr[count])
		free(arr[count++]);
	free(arr);
}
