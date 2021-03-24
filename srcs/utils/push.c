/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 16:10:22 by cmorel-a          #+#    #+#             */
/*   Updated: 2021/03/24 16:53:01 by cmorel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/global.h"

static void	push(t_stack *src, t_stack *dst)
{
	t_number	*tmp;

	if (src->len < 1)
		return ;
	tmp = src->first;
	src->first->prev->next = src->first->next->prev;
	src->first->next->prev = src->first->prev->next;
	src->first = src->first->next;
	tmp->next = tmp;
	tmp->prev = tmp;
	if (dst->len > 0)
	{
		tmp->next = dst->first;
		tmp->prev = dst->first->prev;
		dst->first->prev->next = tmp;
		dst->first->prev = tmp;
		dst->first = dst->first->prev;
	}
	else
		dst->first = tmp;
	src->len--;
	dst->len++;
}

int	push_a(t_all *all)
{
	push(all->b, all->a);
	return (EXIT_SUCCESS);
}

int	push_b(t_all *all)
{
	push(all->a, all->b);
	return (EXIT_SUCCESS);
}
