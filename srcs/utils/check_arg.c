/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 11:59:31 by cmorel-a          #+#    #+#             */
/*   Updated: 2021/03/31 18:17:58 by cmorel-a         ###   ########.fr       */
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
	int			i;

	tmp = all->a->first;
	i = 0;
	while (i < all->a->len)
	{
		if (tmp->value == number)
			return (1);
		tmp = tmp->next;
		i++;
	}
	return (0);
}

static int	check_av_list(int ac, char **av, t_all *all, int i)
{
	int		number;
	int		ret;
	int		is_overflow;

	is_overflow = 0;
	while (i < ac)
	{
		ret = ft_isnumeric(av[i]);
		if (ret)
			return (EXIT_FAILURE);
		number = ft_strtoi(av[i], &is_overflow);
		if (is_overflow)
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

void	check_args(int ac, char **av, t_all *all)
{
	char	**split;
	int		nb_args;
	int		ret;

	if (ac > 2 || (ac == 2 && !ft_test_set(' ', av[1])))
	{
		ret = check_av_list(ac, av, all, 1);
		if (ret)
			error(all);
		return ;
	}
	split = ft_split(av[1], ' ');
	if (split == NULL)
		error(all);
	nb_args = ft_len_tab(split);
	ret = check_av_list(nb_args, split, all, 0);
	split = ft_free_tab(split);
	if (ret)
		error(all);
}
