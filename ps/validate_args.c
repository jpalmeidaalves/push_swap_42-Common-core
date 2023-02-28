/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 19:12:19 by joaoalme          #+#    #+#             */
/*   Updated: 2023/02/24 16:02:23 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_err(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit(EXIT_FAILURE);
}

static int	ft_intrange(long nb)
{
	if (nb < -2147483648 || nb > 2147483647)
		return (0);
	return (1);
}

static int	ft_isnumb(char *arg)
{
	int	i;

	i = 0;
	if (arg[0] == '-')
		i++;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	ft_repeated(char **args, int nb, int i)
{
	i++;
	while (args[i])
	{
		if (ft_atol(args[i]) == nb)
			return (1);
		i++;
	}
	return (0);
}

/* Check if:
	1. Number of arguments is 1. if yes exit and return prompt back
	2. Number of arguments is 2, if yes, split av[1] and create an array of strings with it.
	3. "some arguments aren’t integers, some arguments are bigger than an integer and/or
   there are duplicates"
*/
void	ft_validate_args(int ac, char **av)
{
	char	**args;
	int		i;
	long	nb;

	i = 0;
	if (ac == 1)
		exit(EXIT_FAILURE);
	if (ac == 2)
		args = ft_split(av[1], ' ');
	else
	{
		i = 1;
		args = av;
	}
	while (args[i])
	{
		nb = ft_atol(args[i]);
		if (!ft_intrange(nb))
			ft_err("Error\n");
		if (!ft_isnumb(args[i]))
			ft_err("Error\n");
		if (ft_repeated(args, nb, i))
			ft_err("Error\n");
		i++;
	}
	if (ac == 2)
		free(args);
}
