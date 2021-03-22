/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 16:10:22 by cmorel-a          #+#    #+#             */
/*   Updated: 2021/03/22 12:25:21 by cmorel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/global.h"

int	push_a(t_all *all)
{
	int	ret;

	if (!all->a->first)
		return (EXIT_SUCCESS);
	ret = push_front_number(all->b, all->a->first->value);
	if (ret == EXIT_FAILURE)
		return (EXIT_FAILURE);
	remove_front_number(all->a);
	all->a->len--;
	all->b->len++;
	return (EXIT_SUCCESS);
}

int	push_b(t_all *all)
{
	if (all->a->first)
		all->a->first->prev = all->b->first;
	else
		all->a->last = all->b->first;
	all->a->first = all->b->first;
	all->b->first = all->b->first->next;
	all->b->first->prev = NULL;
	all->b->len--;
	all->a->len++;
	return (EXIT_SUCCESS);
}
