#include "push_swap.h"

int	main(int ac, char **av)
{
	t_element	**stack_a;
	t_element	**stack_b;

	stack_a = malloc(sizeof(t_element));	
	stack_b = malloc(sizeof(t_element));	
	*stack_a = create_stack(ac, av); 
	*stack_b = NULL;
	
	ft_print_stacks(*stack_a, *stack_b);
	pb(stack_a, stack_b);	
	ft_print_stacks(*stack_a, *stack_b);
	pb(stack_a, stack_b);	
	ft_print_stacks(*stack_a, *stack_b);
//	ss(stack_b, stack_a);
//	ft_print_stacks(*stack_a, *stack_b);
	pb(stack_a, stack_b);
        ft_print_stacks(*stack_a, *stack_b);
	rr(stack_a, stack_b);	
	ft_print_stacks(*stack_a, *stack_b);
	rra(stack_a);
	ft_print_stacks(*stack_a, *stack_b);

}
