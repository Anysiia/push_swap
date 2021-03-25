/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 16:15:28 by cmorel-a          #+#    #+#             */
/*   Updated: 2021/03/25 11:55:19 by cmorel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/global.h"

int	rotate_a(t_all *all, int print)
{
	int	ret;

	if (all->a->len > 0)
		all->a->first = all->a->first->next;
	if (print)
	{
		ret = push_back_instruction(all->op, "ra\n");
		if (ret == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	rotate_b(t_all *all, int print)
{
	int	ret;

	if (all->b->len > 0)
		all->b->first = all->b->first->next;
	if (print)
	{
		ret = push_back_instruction(all->op, "rb\n");
		if (ret == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	rotate_all(t_all *all, int print)
{
	int	ret;

	rotate_a(all, 0);
	rotate_b(all, 0);
	if (print)
	{
		ret = push_back_instruction(all->op, "rr\n");
		if (ret == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
