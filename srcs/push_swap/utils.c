/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 15:19:23 by cmorel-a          #+#    #+#             */
/*   Updated: 2021/03/31 18:15:29 by cmorel-a         ###   ########.fr       */
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

void	ra_rra_n_times(t_all *all, int n)
{
	int	i;
	int	dist;

	i = 0;
	if (n > all->a->len / 2)
	{
		dist = all->a->len - n + 1;
		while (dist--)
			reverse_rotate_a(all, 1);
	}
	else
	{
		while (i < (all->a->len - n))
			rotate_a(all, 1);
	}
}
