/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 16:18:05 by cmorel-a          #+#    #+#             */
/*   Updated: 2021/03/31 18:00:56 by cmorel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/global.h"

void	reverse_rotate_a(t_all *all, int print)
{
	int	ret;

	if (all->a->len > 0)
		all->a->first = all->a->first->prev;
	if (print)
	{
		ret = push_back_instruction(all->op, "rra\n");
		if (ret == EXIT_FAILURE)
			error(all);
	}
}

void	reverse_rotate_b(t_all *all, int print)
{
	int	ret;

	if (all->b->len > 0)
		all->b->first = all->b->first->prev;
	if (print)
	{
		ret = push_back_instruction(all->op, "rrb\n");
		if (ret == EXIT_FAILURE)
			error(all);
	}
}

void	reverse_rotate_all(t_all *all, int print)
{
	int	ret;

	reverse_rotate_a(all, 0);
	reverse_rotate_b(all, 0);
	if (print)
	{
		ret = push_back_instruction(all->op, "rrr\n");
		if (ret == EXIT_FAILURE)
			error(all);
	}
}
