#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef	struct s_element
{
	int	nb;
	struct s_element	*next;
}	t_element;

void	ft_print_list(t_element * head) 
{
    	while (head != NULL) 
	{
        	printf("%d\n", head->nb);
        	head = head->next;
    	}
}	

t_element	*creat_node (int nb)
{
	t_element	*new_elm;

	new_elm = malloc(sizeof(t_element));
	if (!new_elm)
		exit (EXIT_FAILURE);
	new_elm->nb = nb;
	new_elm->next = 0;
	return(new_elm);
}

t_element	*create_stacks(int ac, char **av)
{
	t_element	*head_a;
	t_element	*tail_a;
	int	count;

	head_a = creat_node(atoi(av[1]));
	tail_a = head_a;
	count = 2;
	while (count < ac)
	{
		tail_a = add_element_back(atoi(av[count]), tail_a);
		count++;
		}
	return(head_a);
}

int     main(int ac, char **av)
{
	t_element	*head_a;
	t_element	*head_b;

	head_a = create_stacks(ac, av);
	head_b = NULL; 
	ft_print_list(head_a);
}
