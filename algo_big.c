#include "push_swap.h"
/*
int	find_nb_ind(t_element	**stack, int nb)
{
	t_element	*head;

	head = *stack;
	while (head->nb != nb)
		head = head->next
	return (head->index);
}

int	ft_count_moves(t_element **stack_a, t_element **stack_b)
{
	t_element       *h_a:
        t_element       *h_b:
	int	less_moves;
	

}*/

/*
void	algo_big(t_element **stack_a, t_element **stack_b)
{
	int			min;
	t_element	*h_a:
	t_element	*h_b:

	h_a = *stack_a;
	h_b = *stack_b;

	while   (ft_size_list(stack_a) > 3)
	{
		pb(stack_a, stack_b);
		pb(stack_a, stack_b);
		pb(stack_a, stack_b);
		ft_count_moves(h_a, h_b)	
	}
	hard_3(stack_a);
	while (ft_size_list(stack_b) > 0)
		pa(stack_a, stack_b);
}
*/
int	ft_find_distance(t_element **stack, int nb)
{
	t_element	*curr;
	int			dist;

	curr = *stack;
	dist = 0;
	while (curr->nb != nb)
	{
		curr = curr->   next;
		dist++;
	}
	return (dist);
}
/*
int     ft_find_ind_pos(t_element **stack, int ind)
{
        t_element       *curr;
        int                     dist;

        curr = *stack;
        dist = 0;
        while (curr->ind != ind) 
        {
                curr = curr->   next;
                dist++;
        }
        return (dist);
}
*/

void    algo_big(t_element **stack_a, t_element **stack_b)
{
        int                     min;

        while   (ft_size_list(stack_a) > 3)
        {
                min = search_low(stack_a);
                if (ft_find_distance(stack_a, min) <= ft_size_list(stack_a) / 2)
                {
                        while ((*stack_a)->nb != min)
                                ra(stack_a);
                }
                else
                        while ((*stack_a)->nb != min)
                                rra(stack_a);
                pb(stack_a, stack_b);
        }
        hard_3(stack_a);
        while (ft_size_list(stack_b) > 0)
                pa(stack_a, stack_b);
}

