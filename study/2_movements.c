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

t_element	*add_element_back(int nb, t_element *tail)
{
	t_element	*new_node;

	new_node = creat_node(nb);
	tail->next = new_node;
	return(new_node);	
}

t_element	*add_element_front(int nb, t_element **head)
{
	t_element	*new_node;

	new_node = creat_node(nb);
	new_node->next = *head;
	*head = new_node;
	return (new_node);
}

t_element	*create_stacks(int ac, char **av)
//int     main(int ac, char **av)
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


void    sa(t_element *head_a)
{
        int     temp;

        temp = head_a->nb;
        head_a->nb = head_a->next->nb;
        head_a->next->nb = temp;
}

void	pb(t_element *head_a, t_element *head_b)
{
	add_element_front(head_a->nb, &head_b);
}

int     main(int ac, char **av)
{
	t_element	*head_a;
	t_element	*head_b;

	head_a = create_stacks(ac, av);
	head_b = NULL; 
	ft_print_list(head_a);
	printf("\n");
	ft_print_list(head_b);
	sa(head_a);
	printf("\n");
	ft_print_list(head_a);
	pb(head_a, head_b);
	printf("\n");
	ft_print_list(head_b);
}

