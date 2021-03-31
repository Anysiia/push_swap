/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 16:10:22 by cmorel-a          #+#    #+#             */
/*   Updated: 2021/03/31 18:05:18 by cmorel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/global.h"

static void	push(t_stack *src, t_stack *dst)
{
	t_number	*tmp;

	if (src->len < 1)
		return ;
	tmp = src->first;
	src->first->prev->next = src->first->next;
	src->first->next->prev = src->first->prev;
	src->first = src->first->next;
	tmp->next = tmp;
	tmp->prev = tmp;
	if (dst->len > 0)
	{
		tmp->prev = dst->first->prev;
		tmp->next = dst->first;
		dst->first->prev->next = tmp;
		dst->first->prev = tmp;
	}
	dst->first = tmp;
	src->len--;
	dst->len++;
}

void	push_a(t_all *all, int print)
{
	int	ret;

	push(all->b, all->a);
	if (print)
	{
		ret = push_back_instruction(all->op, "pa\n");
		if (ret == EXIT_FAILURE)
			error(all);
	}
}

void	push_b(t_all *all, int print)
{
	int	ret;

	push(all->a, all->b);
	if (print)
	{
		ret = push_back_instruction(all->op, "pb\n");
		if (ret == EXIT_FAILURE)
			error(all);
	}
}
