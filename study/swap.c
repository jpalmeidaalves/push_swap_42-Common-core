/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 20:10:27 by joaoalme          #+#    #+#             */
/*   Updated: 2023/02/05 20:21:57 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sa(t_element *head)
{
        int     temp;

        temp = head->nb;
        head->nb = head->next->nb;
        head->next->nb = temp;
}

int     main(int ac, char **av)
{
	t_element	*head_a;

	head_a = create_stacks(ac, av);
	ft_print_list(head_a);
	printf("\n");
	sa(head_a);
	printf("\n");
	ft_print_list(head_a);
}
