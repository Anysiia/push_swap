/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 11:59:31 by cmorel-a          #+#    #+#             */
/*   Updated: 2021/03/11 13:04:14 by cmorel-a         ###   ########.fr       */
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
	if (number[i] != '\0')
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	is_overflow(char *number)
{
	long int	nb;
	int			sign;

	nb = 0;
	sign = 1;
	if (*number == '-' || *number == '+')
	{
		if (*number == '-')
			sign = -1;
		number++;
	}
	while (ft_isdigit(*number))
	{
		nb = nb * 10 + (*number - 48);
		if ((sign == 1 && nb > INT_MAX) || (sign == -1 && nb * sign < INT_MIN))
			return (EXIT_FAILURE);
		number++;
	}
	return (EXIT_SUCCESS);
}

int	check_args(int ac, char **av, t_list *stack_a)
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
		if (errno = ERANGE)
			return (EXIT_FAILURE);
		add_back_number(number, stack_a);
		i++;
	}
	return (EXIT_SUCCESS);
}

int main(int ac, char **av)
{
	int		ret;
	t_list	*stack_a;
	t_list	*stack_b;

	if (ac == 1)
		return (EXIT_SUCCESS);
	ret = check_args(ac, av, stack_a);
	if (ret)
	{
		write(STDERR, "Error\n", 6);
		return (EXIT_FAILURE);
	}
}
