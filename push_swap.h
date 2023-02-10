/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 20:10:26 by joaoalme          #+#    #+#             */
/*   Updated: 2023/02/09 22:22:32 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_element
{
	int					nb;
	struct s_element	*next;
}						t_element;

void					ft_print_list(t_element **stack);
t_element				*creat_node(int nb);
t_element				*add_element_back(int nb, t_element **head);
void					add_element_front(int nb, t_element **head);
t_element				*create_stack(int ac, char **av, t_element **stack);
t_element				*find_tail(t_element **stack);
int						ft_size_list(t_element **stack);
void	ft_print_stacks(t_element **stack_a,
						t_element **stack_b);
void					pa(t_element **stack_a, t_element **stack_b);
void					pb(t_element **stack_a, t_element **stack_b);
int						push_element(t_element **s_from, t_element **s_to);
void					swap(t_element **stack);
void					sa(t_element **stack_a);
void					sb(t_element **stack_b);
void					ss(t_element **stack_a, t_element **stack_b);
void					rotate(t_element **stack);
void					ra(t_element **stack_a);
void					rb(t_element **stack_b);
void					rr(t_element **stack_a, t_element **stack_b);
void					rev_rot(t_element **stack);
void					rra(t_element **stack_a);
void					rrb(t_element **stack_b);
void					rrr(t_element **stack_a, t_element **stack_b);
void					ft_err(char *msg);
int						ft_intrange(long nb);
int						ft_isnumb(char *arg);
int						ft_repeated(char **args, int nb, int i);
void					ft_validate_args(int ac, char **av);
int						is_sorted(t_element **stack);
void    sorting(t_element **stack_a, t_element **stack_b);
int     search_low(t_element    **stack);
void    hard_3(t_element **stack);
int     search_high(t_element **stack);
void    hard_4(t_element **stack_a, t_element **stack_b);
void    hard_5(t_element **stack_a, t_element **stack_b);
void	free_stack(t_element **stack);

#endif
