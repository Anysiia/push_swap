/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 14:40:50 by cmorel-a          #+#    #+#             */
/*   Updated: 2021/04/25 11:16:49 by cmorel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/global.h"

static void	three_case(t_all *all)
{
	int	value1;
	int	value2;
	int	value3;

	if (all->a->len != 3 || !is_sort_stack(all->a))
		return ;
	value1 = all->a->first->value;
	value2 = all->a->first->next->value;
	value3 = all->a->first->next->next->value;
	if (value1 > value2 && value2 < value3 && value1 < value3)
		return (swap_a(all, 1));
	else if (value1 > value2 && value1 > value3 && value2 < value3)
		return (rotate_a(all, 1));
	else if (value1 < value2 && value1 > value3 && value2 > value3)
		return (reverse_rotate_a(all, 1));
	swap_a(all, 1);
	if (value1 > value2 && value1 > value3 && value2 > value3)
		reverse_rotate_a(all, 1);
	else
		rotate_a(all, 1);
}

static void	five_case(t_all *all)
{
	int	i;
	int	pos;
	int	small;

	i = 0;
	small = 0;
	while (all->a->len > 3)
	{
		pos = find_smaller_number_position(all->a, &small);
		ra_rra(all, pos);
		push_b(all, 1);
		i++;
	}
	three_case(all);
	while (all->b->len > 0)
		push_a(all, 1);
}

static void	select_algo(t_all *all)
{
	int	ret;

	ret = is_sort(all);
	if (!ret)
		return ;
	if (all->a->len == 2)
		swap_a(all, 1);
	else if (all->a->len == 3)
		three_case(all);
	else if (all->a->len == 4 || all->a->len == 5)
		five_case(all);
	else if (all->a->len > 5 && all->a->len <= 50)
		sort(all, 3);
	else if (all->a->len > 50 && all->a->len <= 100)
		sort(all, 9);
	else if (all->a->len > 100 && all->a->len <= 250)
		sort(all, 13);
	else if (all->a->len > 250 && all->a->len <= 500)
		sort(all, 25);
	else if (all->a->len > 500)
		sort(all, all->a->len / 30);
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
