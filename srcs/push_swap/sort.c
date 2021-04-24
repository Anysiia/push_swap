/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 10:58:09 by cmorel-a          #+#    #+#             */
/*   Updated: 2021/04/24 16:42:57 by cmorel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/global.h"

static int	numbers_in_chunks(t_stack *a, int value)
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

int	get_position(t_stack *stack, int limit, int type, int *value)
{
	t_number	*tmp;
	int			pos;

	pos = 0;
	tmp = stack->first;
	while (pos < stack->len && tmp->value > limit)
	{
		if (type == 0)
			tmp = tmp->next;
		else
			tmp = tmp->prev;
		pos++;
	}
	*value = tmp->value;
	return (pos);
}

int	find_pos_b(t_stack *b, int value)
{
	t_number	*tmp;
	int			pos;

	pos = 0;
	if (b->len == 0)
		return (pos);
	tmp = b->first;
	while (pos < b->len && tmp->value > value)
	{
		tmp = tmp->next;
		pos++;
	}
	return (pos);
}

void	find_next_number(t_all *all, int limit)
{
	int		value_top;
	int		value_bottom;
	int		pos_top;
	int		pos_bottom;
	int		pos_b;

	pos_top = get_position(all->a, limit, 0, &value_top);
	pos_bottom = get_position(all->a, limit, 1, &value_bottom);
	if (pos_top > pos_bottom)
		pos_b = find_pos_b(all->b, value_bottom);
	else
		pos_b = find_pos_b(all->b, value_top);
	rb_rrb(all, pos_b);
	if (pos_top > pos_bottom)
		ra_rra(all, all->a->len - pos_bottom);
	else
		ra_rra(all, pos_top);
}

void	sort(t_all *all, int nb_chunks)
{
	int		*list;
	int		i;
	int		nb_in_stack;
	int		j;

	list = get_short_sort_list(all, all->a, nb_chunks);
	i = 0;
	while (i < nb_chunks)
	{
		nb_in_stack = numbers_in_chunks(all->a, list[i]);
		j = 0;
		while (j < nb_in_stack && all->a->len > 0)
		{
			find_next_number(all, list[i]);
			push_b(all, 1);
			j++;
		}
		i++;
	}
	push_b(all, 1);
	push_larger_to_b(all);
	free(list);
}
