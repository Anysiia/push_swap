/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 15:19:23 by cmorel-a          #+#    #+#             */
/*   Updated: 2021/04/24 16:42:16 by cmorel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/global.h"

int	find_smaller_number_position(t_stack *stack, int *small)
{
	int			i;
	int			pos;
	t_number	*tmp;

	i = 1;
	pos = 0;
	*small = stack->first->value;
	tmp = stack->first->next;
	while (i < stack->len)
	{
		if (*small > tmp->value)
		{
			*small = tmp->value;
			pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (pos);
}

int	find_larger_number_position(t_stack *stack, int *larger)
{
	int			i;
	int			pos;
	t_number	*tmp;

	i = 1;
	pos = 0;
	*larger = stack->first->value;
	tmp = stack->first->next;
	while (i < stack->len)
	{
		if (*larger < tmp->value)
		{
			*larger = tmp->value;
			pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (pos);
}

void	ra_rra(t_all *all, int pos)
{
	int	dist;

	if (pos == 0)
		return ;
	else if (pos > all->a->len / 2)
	{
		dist = all->a->len - pos;
		while (dist--)
			reverse_rotate_a(all, 1);
	}
	else
	{
		dist = pos;
		while (dist--)
			rotate_a(all, 1);
	}
}

void	rb_rrb(t_all *all, int pos)
{
	int	dist;

	if (pos == 0)
		return ;
	else if (pos > all->b->len / 2)
	{
		dist = all->b->len - pos;
		while (dist--)
			reverse_rotate_b(all, 1);
	}
	else
	{
		dist = pos;
		while (dist--)
			rotate_b(all, 1);
	}
}

void	push_larger_to_b(t_all *all)
{
	int	pos;
	int	value;

	while (all->b->len > 0)
	{
		pos = find_larger_number_position(all->b, &value);
		rb_rrb(all, pos);
		push_a(all, 1);
	}
}
