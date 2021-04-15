/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 10:58:09 by cmorel-a          #+#    #+#             */
/*   Updated: 2021/04/15 15:50:16 by cmorel-a         ###   ########.fr       */
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

static int	*get_short_sort_list(t_all *all, int parts)
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

static int		numbers_in_chunks(t_stack *a, int value)
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

void	sort(t_all *all, int nb_chunks)
{
	int		*list;
	int		i;
	int		nb_in_stack;
	int		j;

	i = 0;
	list = get_short_sort_list(all, nb_chunks);
	while (i < nb_chunks)
	{
		nb_in_stack = numbers_in_chunks(all->a, list[i]);
		j = 0;
		while (j < nb_in_stack && all->a->len > 0)
		{
			if (all->a->first->value <= list[i])
			{
				push_b(all, 1);
				j++;
			}
			else
				rotate_a(all, 1);
		}
		i++;
	}
	while (all->a->len > 0)
		push_b(all, 1);
	push_larger_to_b(all);
	free(list);
}
