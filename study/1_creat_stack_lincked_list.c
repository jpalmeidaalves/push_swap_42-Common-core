/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_creat_stack_lincked_list.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 20:10:34 by joaoalme          #+#    #+#             */
/*   Updated: 2023/02/05 20:10:41 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef	struct s_element
{
	int	nb;
	struct s_element	*next;
}	t_element;

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
	return(new_elm);
}

t_element	*add_element_back(int nb, t_element *tail)
{
	t_element	*new_node;

	new_node = creat_node(nb);
	tail->next = new_node;
	return(new_node);	
}

void	create_stacks(int ac, char **av)
//int     main(int ac, char **av)
{
	t_element	*head_a;
	t_element	*tail_a;
	t_element	*head_b;
	t_element	*tail_b;
	int	count;

	head_a = creat_node(atoi(av[1]));
	tail_a = head_a;
	head_b = creat_node(0);
	tail_b = creat_node(0);
	count = 2;
	while (count < ac)
	{
		tail_a = add_element_back(atoi(av[count]), tail_a);
		count++;
		}
	ft_print_list(head_a);
	ft_print_list(head_b);
	(void)head_b;
	(void)tail_b;
//	return(0);
}
