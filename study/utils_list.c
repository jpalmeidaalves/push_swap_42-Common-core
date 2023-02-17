/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 20:10:24 by joaoalme          #+#    #+#             */
/*   Updated: 2023/02/07 20:30:41 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_list(t_element * head) 
{
    	while (head != NULL) 
	{
        	printf("%d\n", head->nb);
        	head = head->next;
    	}
}	

t_element	*creat_node (int nb)
{
	t_element	*new_elm;

	new_elm = malloc(sizeof(t_element));
	if (!new_elm)
		exit (EXIT_FAILURE);
	new_elm->nb = nb;
	new_elm->next = 0;
	new_elm->prev = 0;
	return(new_elm);
}

t_element       *find_tail(t_element *head)
{
        t_element       *tail;

        tail = head;
        while (tail->next != NULL)
                tail = tail->next;
        return(tail);
}

int     ft_size_list(t_element **stack)
{
        t_element       *head;
        int     count;

       	count = 0;
	head = *stack; 
        while (head != NULL)
        {
                head = head->next;
                count++;
        }
        return (count);
}

t_element	*add_element_back(int nb, t_element *head)
{
	t_element	*new_node;
	t_element	*tail;
	
	tail = find_tail(head);
	new_node = creat_node(nb);
	tail->next = new_node;
	new_node->prev = tail;
	return(new_node);	
}

void	add_element_front(int nb, t_element **head)
{
	t_element	*new_node;

	new_node = creat_node(nb);
	new_node->next = *head;
	*head = new_node;
}

t_element	*create_stacks(int ac, char **av)
{
	t_element	*head;
	t_element	*tail;
	int	index;

	index = 1;
	head = creat_node(ft_atoi(av[index]));
	tail = head;
	index++;
	while (index < ac)
	{
		tail_a = add_element_back(atoi(av[index]), tail_a);
		index++;
	}
	return(head_a);
}
