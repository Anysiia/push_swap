/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_limit_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 16:22:03 by cmorel-a          #+#    #+#             */
/*   Updated: 2021/04/26 16:44:09 by cmorel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/global.h"

static long	find_number(t_all *all, int count, int min, int max)
{
	t_number	*tmp;
	int			next_min;
	int			i;
	int			j;

	i = 0;
	while (i < count - 1)
	{
		next_min = max;
		tmp = all->a->first;
		j = 0;
		while (j < all->a->len)
		{
			if (tmp->value > min && tmp->value < next_min)
				next_min = tmp->value;
			tmp = tmp->next;
			j++;
		}
		min = next_min;
		i++;
	}
	return (min);
}

int	*get_limit_list(t_all *all, int parts)
{
	int		*list;
	int		min;
	int		max;
	int		count;
	int		i;

	list = (int *)malloc(sizeof(int) * parts);
	if (!list)
		error(all);
	find_smaller_number_position(all->a, &min);
	find_larger_number_position(all->a, &max);
	list[parts - 1] = max;
	i = 0;
	while (i < parts - 1)
	{
		count = all->a->len / parts;
		if (i == 0)
			count += (all->a->len % parts);
		list[i] = find_number(all, count, min, max);
		min = list[i] + 1;
		i++;
	}
	return (list);
}
