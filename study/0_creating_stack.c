#include "libft.h"
#include "push_swap.h"

void	print_stack(int *stk, int nb)
{
	int	i;

	i = 1;
	while(i < nb)
	{
		ft_printf("%d ", stk[i]);
		i++;
	}
	write(1, "\n", 1);
}

int     main(int ac, char **av)
{
        int     stack_a[ac - 1];
	int     stack_b[ac - 1];
        int     i;
	
	i = 1;
	while (i < ac)
	{
		stack_a[i] = ft_atoi(av[i]);
		i++;
	}
	print_stack(stack_a, ac);
	print_stack(stack_b, ac);
}
