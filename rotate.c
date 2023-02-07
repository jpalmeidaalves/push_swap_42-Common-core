#include "push_swap.h"

void	rotate(t_element **stack) 
{
	t_element	*head;
	t_element 	*tail;
	t_element	*current;
	int	tmp;

	head = *stack;
	tail = find_tail(head);
	current = head;
	tmp = head->nb;
	while (current->next != NULL)
	{
		current->nb = current->next->nb;
		current = current->next;
	}
	tail->nb = tmp;
}

void	ra(t_element **stack_a)
{
	rotate(stack_a);
	ft_printf("ra\n");
}

void	rb(t_element **stack_b)
{
	rotate(stack_b);
	ft_printf("rb\n");
}

void	rr(t_element **stack_a, t_element **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");	
}

void	rev_rot(t_element **stack)
{
	t_element	*head;
	t_element       *tail;
        t_element       *current;
        int     tmp;

	head = *stack;
        tail = find_tail(head);
        current = tail;
        tmp = tail->nb;
        while (current->prev != NULL)
        {
		current->nb = current->prev->nb;
		current = current->prev;
        }
        head->nb = tmp;
}

void	rra(t_element **stack_a)
{
	rev_rot(stack_a);
	ft_printf("rra\n");
}

void	rrb(t_element **stack_b)
{
	rev_rot(stack_b);
	ft_printf("rrb\n");
}

void	rrr(t_element **stack_a, t_element **stack_b)
{
	rev_rot(stack_a);
	rev_rot(stack_b);
	ft_printf("rrr\n");	
}
/*
int     main(int ac, char **av)
{
	t_element	*head_a;
	
	head_a = create_stacks(ac, av);
	printf("stack a:\n");
	ft_print_list(head_a);
	
	rra(&head_a);
	printf("stack a:\n");
	ft_print_list(head_a);

	ra(&head_a);
	printf("stack a:\n");
	ft_print_list(head_a);

	return 0;	
}*/
