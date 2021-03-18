/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 11:59:31 by cmorel-a          #+#    #+#             */
/*   Updated: 2021/03/18 13:14:32 by cmorel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/global.h"

int	ft_isnumeric(char *number)
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
		push_back_number(all->a, number);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	int		ret;
	t_all	tmp;

	if (ac == 1)
		return (EXIT_SUCCESS);
	init_all(&tmp);
	ret = check_args(ac, av, &tmp);
	if (ret)
		return (error(&tmp));
}
