#include "push_swap.h"

void	rotate(t_element *head) 
{
	t_element 	*tail;
	t_element	*current;
	int	tmp;

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

void	rev_rot(t_element *head)
{
	t_element       *tail;
        t_element       *current;
        int     tmp;

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

int     main(int ac, char **av)
{
	t_element	*head_a;
	
	head_a = create_stacks(ac, av);
	printf("stack a:\n");
	ft_print_list(head_a);
	
	rev_rot(head_a);
	printf("stack a:\n");
	ft_print_list(head_a);

	rotate(head_a);
	printf("stack a:\n");
	ft_print_list(head_a);


	

	return 0;	

}
