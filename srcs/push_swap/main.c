/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 14:40:50 by cmorel-a          #+#    #+#             */
/*   Updated: 2021/03/31 16:12:10 by cmorel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/global.h"

int	five_case(t_all *all)
{
	int	i;
	int	pos;
	int	small;

	i = 0;
	small = 0;
	while (all->a->len > 3)
	{
		pos = find_smaller_number_position(all->a, &small);
		ra_rra_n_times(all, pos);
		push_b(all, 1);
		i++;
	}
	three_case(all);
	while (i > 0)
	{
		push_a(all, 1);
		i--;
	}
	return (EXIT_SUCCESS);
}

int	select_algo(t_all *all)
{
	int	ret;

	ret = is_sort(all);
	if (!ret)
		return (EXIT_SUCCESS);
	if (all->a->len == 2)
		return (swap_a(all, 1));
	else if (all->a->len == 3)
		return (three_case(all));
	else if (all->a->len == 4 || all->a->len == 5)
		return (five_case(all));
	else if (all->a->len < 50)
		return (five_case(all));
/*	else
		return (quick_sort(all));*/
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
	ret = select_algo(&tmp);
	if (ret)
		return (error(&tmp));
	print_operation_list(&tmp);
	free_all(&tmp);
	return (EXIT_SUCCESS);
}
