/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_short_sort_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 15:29:00 by cmorel-a          #+#    #+#             */
/*   Updated: 2021/04/24 15:47:49 by cmorel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/global.h"

static int	*bubble_sort(int *median, int parts)
{
	int	i;
	int	j;
	int	swap;

	i = 0;
	while (i < parts)
	{
		j = 0;
		while (j < parts)
		{
			if (median[i] < median[j])
			{
				swap = median[i];
				median[i] = median[j];
				median[j] = swap;
			}
			j++;
		}
		i++;
	}
	return (median);
}

int	*get_short_sort_list(t_all *all, t_stack *stack, int parts)
{
	t_number	*tmp;
	int			i;
	int			*median;
	int			index;

	i = 0;
	index = 1;
	tmp = stack->first;
	median = (int *)malloc(sizeof(int) * parts);
	if (!median)
		error(all);
	median[0] = stack->first->value;
	while (i < stack->len && index < parts - 1)
	{
		if (i == (stack->len / parts * index))
		{
			median[index] = tmp->value;
			index++;
		}
		i++;
		tmp = tmp->next;
	}
	find_larger_number_position(stack, &median[parts - 1]);
	median = bubble_sort(median, parts);
	return (median);
}

int		pivot_stack(t_all *all, t_stack *stack)
{
	int	parts;
	int	*median;
	int	pivot;

	if (stack->len > 3 && stack->len <= 50)
		parts = 3;
	else if (stack->len > 50 && stack->len <= 100)
		parts = 5;
	else if (stack->len > 100 && stack->len <= 250)
		parts = 9;
	else if (stack->len > 250 && stack->len <= 500)
		parts = 11;
	else
		parts = 13;
	median = get_short_sort_list(all, stack, parts);
	pivot = median[parts/2];
	free(median);
	median = NULL;
	return (pivot);
}
