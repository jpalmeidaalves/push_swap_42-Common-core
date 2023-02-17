/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 20:10:26 by joaoalme          #+#    #+#             */
/*   Updated: 2023/02/06 19:41:41 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_element
{
	int					nb;
	struct s_element	*next;
	struct s_element	*prev;
}						t_element;

void					ft_print_list(t_element *head);
t_element				*creat_node(int nb);
t_element				*add_element_back(int nb, t_element *head);
void					add_element_front(int nb, t_element **head);
t_element				*create_stacks(int ac, char **av);
t_element				*find_tail(t_element *head);
int					ft_size_list(t_element **stack);

#endif
