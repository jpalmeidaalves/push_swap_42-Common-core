/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 20:10:26 by joaoalme          #+#    #+#             */
/*   Updated: 2023/04/21 15:27:20 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../libft/libft.h"
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_element
{
	int					nb;
	struct s_element	*next;
}						t_element;
t_element				*creat_node(int nb);
t_element				*add_element_back(int nb, t_element **head);
t_element				*find_tail(t_element **stack);
int						f_size_l(t_element **stack);

int						pa(t_element **stack_a, t_element **stack_b);
int						pb(t_element **stack_a, t_element **stack_b);
int						sa(t_element **stack_a);
int						sb(t_element **stack_b);
int						ss(t_element **stack_a, t_element **stack_b);
int						ra(t_element **stack_a);
int						rb(t_element **stack_b);
int						rr(t_element **stack_a, t_element **stack_b);
int						rra(t_element **stack_a);
int						rrb(t_element **stack_b);
int						rrr(t_element **stack_a, t_element **stack_b);

void					ft_validate_args(int ac, char **av);
int						is_sorted(t_element **stack);
int						f_min(t_element **stack);
int						f_max(t_element **stack);
void					free_stack(t_element **stack_a, t_element **stack_b);
void					simple_sort(t_element **stack_a, t_element **stack_b);
void					hard_3(t_element **stack);
void					big_sort(t_element **stack_a, t_element **stack_b);

int						f_rrarrb(t_element *a, t_element *b, int nb);
int						f_rrarrb_a(t_element *a, t_element *b, int nb);
int						apply_rrarrb(t_element **a, t_element **b, int nb,
							char s);
int						f_rarb(t_element *a, t_element *b, int nb);
int						f_rarb_a(t_element *a, t_element *b, int nb);
int						apply_rarb(t_element **a, t_element **b, int nb,
							char s);
int						f_rrarb(t_element *a, t_element *b, int nb);
int						f_rrarb_a(t_element *a, t_element *b, int nb);
int						apply_rrarb(t_element **a, t_element **b, int nb,
							char s);
int						f_rarrb(t_element *a, t_element *b, int nb);
int						f_rarrb_a(t_element *a, t_element *b, int nb);
int						apply_rarrb(t_element **a, t_element **b, int nb,
							char s);

void					sort_big(t_element **stack_a, t_element **stack_b);
int						f_distance(t_element *stack, int nb);
t_element				*sorting_b(t_element **s_a);
void					sort_b_3(t_element **s_a, t_element **s_b);
t_element				*sorting_a(t_element **sa, t_element **sb);
int						find_out_move_ab(t_element *a, t_element *b);
int						find_out_move_ba(t_element *a, t_element *b);
int						f_position_in_b(t_element **stack, int nb);
int						f_position_in_a(t_element **stack, int nb);

void					ft_print_list(t_element **stack);
void					ft_print_stacks(t_element **stack_a,
							t_element **stack_b);
void					free_args(char **arr);
void					build_stack(char **args, t_element *tail, int count);
t_element				*create_stack(int ac, char **av, t_element **stack);
void					final_check(t_element **stack_a);
void					free_stack(t_element **stack_a, t_element **stack_b);
void					sorting(t_element **stack_a, t_element **stack_b,
							int nb_elem);
int						rotate(t_element **stack);
int						rev_rot(t_element **stack);
int						swap(t_element **stack);
int						push(t_element **s_from, t_element **s_to);

#endif
