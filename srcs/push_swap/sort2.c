/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 11:32:46 by cmorel-a          #+#    #+#             */
/*   Updated: 2021/04/24 12:38:16 by cmorel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/global.h"

int		ft_pivot(t_stack *stack)
{
	return (stack->first->value);
}

int		need_push(t_stack *stack, int id, int len, int pivot)
{
	t_number	*tmp;

	tmp = stack->first;
	while (len--)
	{
		if (id == 1 && tmp->value < pivot)
			return (1);
		else if (id == 2 && tmp->value > pivot)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	backtrack_stack_a(t_all *all, t_stack *a, int r)
{
	if (r > a->len / 2)
		while (a->len - r++ > 0)
			rotate_a(all, 1);
	else
		while (r--)
			reverse_rotate_a(all, 1);
}

int		sort_a(t_all *all, int len)
{
	int		pivot;
	int		p;
	int		r;
	int		i;

	r = 0;
	i = 0;
	p = 0;
	if (len <= 3)
		return (ft_sort_a(all, len));
	pivot = ft_pivot(all->a);
	while (need_push(all->a, 1, len - i, pivot) && i++ < len)
		if (all->a->first->value < pivot && ++p)
			push_b(all, 1);
		else
		{
			rotate_a(all, 1);
			r++;
		}
	backtrack_stack_a(all, all->a, r);
	sort_a(all, len - p);
	sort_b(all, p);
	while (p--)
		push_a(all, 1);
	return (0);
}

void	backtrack_stack_b(t_all *all, t_stack *b, int r)
{
	if (r > all->b->len / 2)
		while (all->b->len - r++ > 0)
			rotate_b(all, 1);
	else
		while (r--)
			reverse_rotate_b(all, 1);
}

int		sort_b(t_all *all, int len)
{
	int		pivot;
	int		p;
	int		r;
	int		i;

	r = 0;
	i = 0;
	p = 0;
	if (len <= 3)
		return (ft_sort_b(all, len));
	pivot = ft_pivot(all->b);
	while (need_push(all->b, 2, len - i, pivot) && i++ < len)
		if (all->b->first->value > pivot && ++p)
			push_a(all, 1);
		else
		{
			rotate_b(all, 1);
			r++;
		}
	sort_a(all, p);
	backtrack_stack_b(all, all->b, r);
	sort_b(all, len - p);
	while (p--)
		push_b(all, 1);
	return (0);
}

int		ft_sort_asc(t_all *all, int len)
{
	while (len-- > 1)
	{
		if (all->a->first->value > all->a->first->next->value)
		{
			swap_a(all, 1);
			rotate_a(all, 1);
		}
		else
			rotate_a(all, 1);
	}
	while (++len < 3)
		reverse_rotate_a(all, 1);
	if (all->a->first->value > all->a->first->next->value)
		swap_a(all, 1);
	return (0);
}

int		ft_sort_desc(t_all *all, int len)
{
	while (len-- > 1)
	{
		if (all->b->first->value < all->b->first->next->value)
		{
			swap_b(all, 1);
			rotate_b(all, 1);
		}
		else
			rotate_b(all, 1);
	}
	while (++len < 3)
		reverse_rotate_b(all, 1);
	if (all->b->first->value < all->b->first->next->value)
		swap_b(all, 1);
	return (0);
}

void	ft_sort_a_onplace(t_all *all, int len)
{
	int		x;
	int		y;
	int		z;

	x = all->a->first->value;
	y = all->a->first->next->value;
	z = all->a->first->next->next->value;
	if (x > y && y > z)
	{
		swap_a(all, 1);
		reverse_rotate_a(all, 1);
	}
	else if (x > z && z > y)
		rotate_a(all, 1);
	else if (z > x && x > y)
		swap_a(all, 1);
	else if (y > z && z > x)
	{
		reverse_rotate_a(all, 1);
		swap_a(all, 1);
	}
	else if (y > x && x > z)
		reverse_rotate_a(all, 1);
}

int		ft_sort_a(t_all *all, int len)
{
	int		x;
	int		y;
	int		z;

	x = all->a->first->value;
	y = 0;
	if (len > 1)
		y = all->a->first->next->value;
	z = 0;
	if (len > 2)
		z = all->a->first->next->next->value;
	if (len == 1)
		return (0);
	else if (len == 2 && x > y)
		swap_a(all, 1);
	else if (all->a->len == 3 && len == 3)
		ft_sort_a_onplace(all, len);
	else
		ft_sort_asc(all, len);
	return (0);
}

void	ft_sort_b_onplace(t_all *all, int len)
{
	int		x;
	int		y;
	int		z;

	x = all->b->first->value;
	y = all->b->first->next->value;
	z = all->b->first->next->next->value;
	if (x < y && y < z)
	{
		swap_b(all, 1);
		reverse_rotate_b(all, 1);
	}
	else if (x < z && z < y)
		rotate_b(all, 1);
	else if (z < x && x < y)
		swap_b(all, 1);
	else if (y < z && z < x)
	{
		reverse_rotate_b(all, 1);
		swap_b(all, 1);
	}
	else if (y < x && x < z)
		reverse_rotate_b(all, 1);
}

int		ft_sort_b(t_all *all, int len)
{
	int		x;
	int		y;
	int		z;

	x = all->b->first->value;
	if (len > 1)
		y = all->b->first->next->value;
	if (len > 2)
		z = all->b->first->next->next->value;
	if (len == 1)
		return (0);
	else if (len == 2 && x < y)
		swap_b(all, 1);
	else if (all->b->len == 3 && len == 3)
		ft_sort_b_onplace(all, len);
	else if (len == 3)
		ft_sort_desc(all, len);
	return (0);
}
