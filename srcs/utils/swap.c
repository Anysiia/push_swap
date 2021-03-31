/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 16:11:57 by cmorel-a          #+#    #+#             */
/*   Updated: 2021/03/31 18:07:57 by cmorel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/global.h"

void	swap_a(t_all *all, int print)
{
	int	tmp;
	int	ret;

	if (all->a->len > 1)
	{
		tmp = all->a->first->next->value;
		all->a->first->next->value = all->a->first->value;
		all->a->first->value = tmp;
	}
	if (print)
	{
		ret = push_back_instruction(all->op, "sa\n");
		if (ret == EXIT_FAILURE)
			error(all);
	}
}

void	swap_b(t_all *all, int print)
{
	int	tmp;
	int	ret;

	if (all->b->len > 1)
	{
		tmp = all->b->first->next->value;
		all->b->first->next->value = all->b->first->value;
		all->b->first->value = tmp;
	}
	if (print)
	{
		ret = push_back_instruction(all->op, "sb\n");
		if (ret == EXIT_FAILURE)
			error(all);
	}
}

void	swap_all(t_all *all, int print)
{
	int	ret;

	swap_a(all, 0);
	swap_b(all, 0);
	if (print)
	{
		ret = push_back_instruction(all->op, "ss\n");
		if (ret == EXIT_FAILURE)
			error(all);
	}
}
