/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 11:59:31 by cmorel-a          #+#    #+#             */
/*   Updated: 2021/03/18 15:10:36 by cmorel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/global.h"

static int	ft_isnumeric(char *number)
{
	int	i;

	i = 0;
	if (number[i] == '-' || number[i] == '+')
		i++;
	while (number[i] && ft_isdigit(number[i]) == 1)
		i++;
	if (number[i])
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	is_inlist(t_all *all, int number)
{
	t_number	*tmp;

	tmp = all->a->first;
	while (tmp)
	{
		if (tmp->value == number)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	check_args(int ac, char **av, t_all *all)
{
	int		i;
	int		number;
	int		ret;

	i = 1;
	while (i < ac)
	{
		ret = ft_isnumeric(av[i]);
		if (ret)
			return (EXIT_FAILURE);
		number = ft_atoi(av[i]);
		if (errno == ERANGE)
			return (EXIT_FAILURE);
		ret = is_inlist(all, number);
		if (ret)
			return (EXIT_FAILURE);
		ret = push_back_number(all->a, number);
		if (ret)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}
