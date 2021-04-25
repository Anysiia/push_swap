/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 14:53:23 by cmorel-a          #+#    #+#             */
/*   Updated: 2021/04/25 15:34:59 by cmorel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/global.h"

static int	set_min(int nb, int min, int *pos_min, int i)
{
	if (nb < min)
	{
		*pos_min = i;
		min = nb;
	}
	return (min);
}

static int	set_max(int nb, int max, int *pos_max, int i)
{
	if (nb > max)
	{
		*pos_max = i;
		max = nb;
	}
	return (max);
}

static void	find_pos(t_stack *stack, int *pos_min, int *pos_max)
{
	t_number	*tmp;
	int			nb;
	int			min;
	int			max;
	int			i;

	tmp = stack->first;
	i = 0;
	while (i < stack->len)
	{
		nb = tmp->value;
		if (i == 0)
		{
			min = nb;
			max = nb;
			*pos_min = i;
			*pos_max = i;
		}
		min = set_min(nb, min, pos_min, i);
		max = set_max(nb, max, pos_max, i);
		i++;
		tmp = tmp->next;
	}
}

static void count_moves(t_info *min, t_info *max, int len)
{
	min->moves = len - min->pos;
	min->dir = 1;
	if (min->pos < len / 2)
	{
		min->moves = min->pos;
		min->dir = 0;
	}
	max->moves = len - max->pos;
	max->dir = 1;
	if (max->pos < len / 2)
	{
		max->moves = max->pos;
		max->dir = 0;
	}
}

void	fill_a(t_all *all, int *remain)
{
	t_info	min;
	t_info	max;
	t_info	final;

	while (all->b->len > 0)
	{
		find_pos(all->b, &min.pos, &max.pos);
		count_moves(&min, &max, all->b->len);
		final = max;
		if (min.moves < max.moves)
			final = min;
		else
			(*remain)++;
		while (final.moves > 0)
		{
			if (!final.dir)
				rotate_b(all, 1);
			else
				reverse_rotate_b(all, 1);
			final.moves--;
		}
		push_a(all, 1);
		if (final.pos != max.pos && all->a->len > 1)
			rotate_a(all, 1);
	}
}
