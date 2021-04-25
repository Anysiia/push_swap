/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_limit_values.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 15:29:00 by cmorel-a          #+#    #+#             */
/*   Updated: 2021/04/25 10:28:13 by cmorel-a         ###   ########.fr       */
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

static int	*short_sort_list(t_all *all, int *sort_list, int len, int parts)
{
	int		i;
	int		index;
	int		*short_tab;

	i = 0;
	index = 1;
	short_tab = (int *)malloc(sizeof(int) * parts);
	if (!short_tab)
		error(all);
	while (i < len && index < parts - 1)
	{
		if (i == (len / parts * index))
		{
			short_tab[index] = sort_list[i];
			index++;
		}
		i++;
	}
	short_tab[index] = sort_list[len - 1];
	return (short_tab);
}

int	*get_limit_values(t_all *all, t_stack *stack, int parts)
{
	t_number	*tmp;
	int			i;
	int			*median;
	int			*short_tab;

	i = 0;
	tmp = stack->first;
	median = (int *)malloc(sizeof(int) * stack->len);
	if (!median)
		error(all);
	while (i < stack->len)
	{
		median[i] = tmp->value;
		i++;
		tmp = tmp->next;
	}
	median = bubble_sort(median, stack->len);
	short_tab = short_sort_list(all, median, stack->len, parts);
	free(median);
	return (short_tab);
}

