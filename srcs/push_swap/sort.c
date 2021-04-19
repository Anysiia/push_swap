/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 10:58:09 by cmorel-a          #+#    #+#             */
/*   Updated: 2021/04/19 17:11:20 by cmorel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/global.h"

static int		numbers_in_chunks(t_stack *a, int value)
{
	t_number	*tmp;
	int			nb;

	nb = 0;
	tmp = a->first->next;
	if (a->first->value == value)
		nb++;
	while (tmp != a->first)
	{
		if (tmp->value <= value)
			nb++;
		tmp = tmp->next;
	}
	return (nb);
}

int		get_position(t_stack *a, int limit, int type)
{
	t_number	*tmp;
	int			pos;

	pos = 0;
	tmp = a->first;
	while (pos < a->len && tmp->value > limit)
	{
		if (type == 0)
			tmp = tmp->next;
		else
			tmp = tmp->prev;
		pos++;
	}
	return (pos);
}

void	find_next_number(t_all *all, int limit)
{
	int		pos_top;
	int		pos_bottom;

	pos_top = get_position(all->a, limit, 0);
	pos_bottom = get_position(all->a, limit, 0);
	if (pos_top > pos_bottom)
		ra_rra_n_times(all, all->a->len - pos_bottom - 1);
	else
		ra_rra_n_times(all, pos_top);
}

void	sort(t_all *all, int nb_chunks)
{
	int		*list;
	int		i;
	int		nb_in_stack;
	int		j;

	list = get_short_sort_list(all, nb_chunks);
	i = 0;
	while (i < nb_chunks)
	{
		nb_in_stack = numbers_in_chunks(all->a, list[i]);
		j = 0;
		while (j < nb_in_stack && all->a->len > 0)
		{
			if (all->a->first->value > list[i])
				find_next_number(all, list[i]);
			push_b(all, 1);
			j++;
		}
		i++;
	}
	while (all->a->len > 0)
		push_b(all, 1);
	push_larger_to_b(all);
	free(list);
}
