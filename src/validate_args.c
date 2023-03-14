/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaoalme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 19:12:19 by joaoalme          #+#    #+#             */
/*   Updated: 2023/03/02 20:02:37 by joaoalme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_err(char *msg)
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

void	ft_validate_args(int ac, char **av)
{
	char	**args;
	int		i;
	long	nb;

	i = 0;
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
		free_args(args);
}
