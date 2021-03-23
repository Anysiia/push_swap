/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 11:59:31 by cmorel-a          #+#    #+#             */
/*   Updated: 2021/03/23 12:28:17 by cmorel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/global.h"

int	checker(t_all *all)
{
	t_number	*tmp;

	if (all->b->len != 0)
		return (EXIT_FAILURE);
	tmp = all->a->first;
	while (tmp && tmp->next != all->a->first)
	{
		if (tmp->value > tmp->next->value)
			return (EXIT_FAILURE);
		tmp = tmp->next;
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
	ret = get_instruction(&tmp);
	if (ret)
		return (error(&tmp));
	ret = execute_all_instruction(&tmp);
	if (ret)
		return (error(&tmp));
	ret = checker(&tmp);
	if (ret)
		ft_putstr("KO\n");
	else
		ft_putstr("OK\n");
//	print_stacks(&tmp);
	free_all(&tmp);
	return (EXIT_SUCCESS);
}
