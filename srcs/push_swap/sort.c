/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 10:58:09 by cmorel-a          #+#    #+#             */
/*   Updated: 2021/04/24 18:23:01 by cmorel-a         ###   ########.fr       */
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
	tmp = b->first->next;
	if (b->first->value < value)
		pos++;
	while (tmp != b->first)
	{
		tmp = tmp->next;
		if (tmp->value < value)
			pos++;
	}
	return (pos);
}

void	print_values(t_all *all, int limit, int value_top, int value_bottom, int pos_top, int pos_bottom, int pos_b)
{
	int			i;
	t_number	*tmp;

	i = 0;
	tmp = all->a->first;
	ft_putstr("-----------\nStack a: ");
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
	ft_putstr("\n\nLimit: ");
	ft_putnbr(limit);
	ft_putstr("\nPos top: ");
	ft_putnbr(pos_top);
	ft_putstr(" Value: ");
	ft_putnbr(value_top);
	ft_putstr("\nPos bot: ");
	ft_putnbr(pos_bottom);
	ft_putstr(" Value: ");
	ft_putnbr(value_bottom);
	ft_putstr("\nPos b: ");
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
	print_values(all, limit, value_top, value_bottom, pos_top, pos_bottom, pos_b);
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
