#include "push_swap.h"

void	push_b(t_element *head_b, t_element *head_a)
{
	

}

int     main(int ac, char **av)
{
	
	t_element	*head_a;
	t_element	*head_b;
	
	head_a = create_stacks(ac, av);
	head_b = NULL;
	printf("stack a:\n");
	ft_print_list(head_a);

	push_b(head_b, head_a);
	printf("stack b:\n");
	ft_print_list(head_b);
	printf("stack a:\n");
	ft_print_list(head_a);

}
