/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 10:38:16 by cmorel-a          #+#    #+#             */
/*   Updated: 2021/04/25 11:24:31 by cmorel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/global.h"

int	is_sort(t_all *all)
{
	if (all->b->len != 0)
		return (EXIT_FAILURE);
	return (is_sort_stack(all->a));
}

int	is_sort_stack(t_stack *stack)
{
	t_number	*tmp;

	tmp = stack->first;
	while (tmp && tmp->next != stack->first)
	{
		if (tmp->value > tmp->next->value)
			return (EXIT_FAILURE);
		tmp = tmp->next;
	}
	return (EXIT_SUCCESS);
}

int	is_reverse_sort_stack(t_stack *stack)
{
	t_number	*tmp;

	tmp = stack->first;
	while (tmp && tmp->next != stack->first)
	{
		if (tmp->value < tmp->next->value)
			return (EXIT_FAILURE);
		tmp = tmp->next;
	}
	return (EXIT_SUCCESS);
}
