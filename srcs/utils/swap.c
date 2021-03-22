/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 16:11:57 by cmorel-a          #+#    #+#             */
/*   Updated: 2021/03/22 11:09:33 by cmorel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/global.h"

int	swap_a(t_all *all)
{
	int	tmp;

	if (all->a->len > 1)
	{
		tmp = all->a->first->next->value;
		all->a->first->next->value = all->a->first->value;
		all->a->first->value = tmp;
	}
	return (EXIT_SUCCESS);
}

int	swap_b(t_all *all)
{
	int	tmp;

	if (all->b->len > 1)
	{
		tmp = all->b->first->next->value;
		all->b->first->next->value = all->b->first->value;
		all->b->first->value = tmp;
	}
	return (EXIT_SUCCESS);
}

int swap_all(t_all *all)
{
	int	ret;

	ret = swap_a(all);
	if (ret == EXIT_FAILURE)
		return (EXIT_FAILURE);
	ret = swap_b(all);
	if (ret == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
