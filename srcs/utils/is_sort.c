/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 10:38:16 by cmorel-a          #+#    #+#             */
/*   Updated: 2021/04/02 17:07:10 by cmorel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/global.h"

int	is_sort(t_all *all)
{
	t_number	*tmp;

	if (all->b->len != 0)
		return (EXIT_FAILURE);
	tmp = all->a->first;
	while (tmp && tmp->next != all->a->first)
	{
		if (tmp->value > tmp->next->value)
			return (EXIT_FAILURE);
		tmp = tmp->next;
	}
	return (EXIT_SUCCESS);
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
