/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_short_sort_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 15:29:00 by cmorel-a          #+#    #+#             */
/*   Updated: 2021/04/19 15:29:44 by cmorel-a         ###   ########.fr       */
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

int	*get_short_sort_list(t_all *all, int parts)
{
	t_number	*tmp;
	int			i;
	int			*median;
	int			index;

	i = 0;
	index = 1;
	tmp = all->a->first;
	median = (int*)malloc(sizeof(int) * parts);
	if (!median)
		error(all);
	median[0] = all->a->first->value;
	while (i < all->a->len && index < parts)
	{
		if (i == (all->a->len / parts * index))
		{
			median[index] = tmp->value;
			index++;
		}
		i++;
		tmp = tmp->next;
	}
	median = bubble_sort(median, parts);
	return (median);
}
