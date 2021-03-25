/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 14:40:50 by cmorel-a          #+#    #+#             */
/*   Updated: 2021/03/25 12:11:04 by cmorel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/global.h"

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
	else if (all->a->len < 50)
		return (insert_sort(all));
	else
		return (quick_sort(all));
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
	print_operation_list(&tmp);
	free_all(&tmp);
	return (EXIT_SUCCESS);
}
