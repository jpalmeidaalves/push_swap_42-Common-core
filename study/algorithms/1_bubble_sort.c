#include "libft.h"

void	print_stack(int *stk, int nb)
{
	int	i;

	i = 0;
	while(i < nb - 1)
	{
		ft_printf("%d ", stk[i]);
		i++;
	}
	write(1, "\n", 1);
}

void	swap(int *a, int *b)
{
	int	temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
/*
int	main()
{
	int list[] = {5, 7};

	swap(&list[0], &list[1]);
	printf("list[0] = %d | list[1] = %d", list[0], list[1]);	
}*/


void	bubble_sort(int *list, int nb_elem)
{
	int	i;
	int	swap_count;

	swap_count = -1;
	while (swap_count != 0)
	{
		i = 0;
		swap_count = 0;
		while (i < nb_elem - 1)
		{
			if (list[i] > list[i + 1])
			{
				swap(&list[i], &list[i + 1]);
				swap_count++;
			}
			i++;
		}
	}
}

int	main(int ac, char **av)
{
        int     stack[ac - 1];
        int     i;
	
	i = 0;
	while (i < ac - 1)
	{
		stack[i] = ft_atoi(av[i + 1]);
		i++;
	}
	printf("Before bubble sort:\n");
	print_stack(stack, ac);
	bubble_sort(stack, ac - 1);
	printf("After bubble sort:\n");
	print_stack(stack, ac);
	return(0);
}

