/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 14:40:50 by cmorel-a          #+#    #+#             */
/*   Updated: 2021/04/13 10:45:41 by cmorel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/global.h"

void	five_case(t_all *all)
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
}

void	select_algo(t_all *all)
{
	int	ret;

	ret = is_sort(all);
	if (!ret)
		return ;
	if (all->a->len == 2)
		swap_a(all, 1);
	else if (all->a->len == 3)
		three_case(all);
	else if (all->a->len > 3 && all->a->len < 50)
		five_case(all);
	else
		quick_sort(all);
}

int	main(int ac, char **av)
{
	t_all	tmp;

	if (ac == 1)
		return (EXIT_SUCCESS);
	init_all(&tmp);
	check_args(ac, av, &tmp);
	select_algo(&tmp);
	print_operation_list(&tmp);
	free_all(&tmp);
	return (EXIT_SUCCESS);
}
