/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 10:58:09 by cmorel-a          #+#    #+#             */
/*   Updated: 2021/04/24 11:11:54 by cmorel-a         ###   ########.fr       */
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

void	print_position_and_value(t_all *all, int limit, int pos_top, int pos_bottom, int value_top, int value_bottom, int pos_b)
{
	t_number	*tmp;
	int			i;

	ft_putstr("---------\nStack a: ");
	tmp = all->a->first;
	i = 0;
	while (i < all->a->len)
	{
		ft_putstr("[");
		ft_putnbr(i);
		ft_putstr("]");
		ft_putnbr(tmp->value);
		ft_putstr(" ");
		tmp = tmp->next;
		i++;
	}
	i = 0;
	tmp = all->b->first;
	ft_putstr("\n\nStack b: ");
	while (i < all->b->len)
	{
		ft_putstr("[");
		ft_putnbr(i);
		ft_putstr("]");
		ft_putnbr(tmp->value);
		ft_putstr(" ");
		tmp = tmp->next;
		i++;
	}
	ft_putstr("\nLimit: ");
	ft_putnbr(limit);
	ft_putstr("\nPosition top: ");
	ft_putnbr(pos_top);
	ft_putstr(" value top: ");
	ft_putnbr(value_top);
	ft_putstr("\nPosition bottom: ");
	ft_putnbr(pos_bottom);
	ft_putstr(" value bottom: ");
	ft_putnbr(value_bottom);
	ft_putstr("\nPosition b: ");
	ft_putnbr(pos_b);
	ft_putstr("\n");
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
//	print_position_and_value(all, limit, pos_top, pos_bottom, value_top, value_bottom, pos_b);
	rb_rrb_n_times(all, pos_b);
	if (pos_top > pos_bottom)
		ra_rra_n_times(all, all->a->len - pos_bottom);
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
