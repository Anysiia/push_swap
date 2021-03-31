/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 15:19:23 by cmorel-a          #+#    #+#             */
/*   Updated: 2021/03/31 16:11:21 by cmorel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/global.h"

int	find_smaller_number_position(t_stack *stack, int *small)
{
	int			i;
	int			pos;
	t_number	*tmp;

	i = 1;
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
	return (i);
}

int	find_larger_number_position(t_stack *stack, int *larger)
{
	int			i;
	int			pos;
	t_number	*tmp;

	i = 1;
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
	return (i);
}

int	ra_rra_n_times(t_all *all, int n)
{
	int	i;
	int	dist;
	int	ret;

	i = 0;
	if (n > all->a->len / 2)
	{
		dist = all->a->len - n + 1;
		while (dist--)
		{
			ret = reverse_rotate_a(all, 1);
			if (ret)
				return (EXIT_FAILURE);
			i++;
		}
	}
	else
	{
		while (i < (all->a->len - n))
		{
			ret = rotate_a(all, 1);
			if (ret)
				return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

int	rb_rrb_n_times(t_all *all, int n)
{
	int	i;
	int	ret;

	i = 0;
	if (n > all->b->len / 2)
	{
		while (i < n)
		{
			ret = reverse_rotate_b(all, 1);
			if (ret)
				return (EXIT_FAILURE);
			i++;
		}
	}
	else
	{
		while (i < (all->b->len - n))
		{
			ret = rotate_b(all, 1);
			if (ret)
				return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}
