/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_utils_variables.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 11:31:47 by cmorel-a          #+#    #+#             */
/*   Updated: 2021/04/25 11:47:05 by cmorel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/global.h"

static int	find_median(t_all *all, int nb_numbers, int min)
{
	t_number	*tmp;
	int			next_min;
	int			number;
	int			i;
	int			j;

	i = 0;
	while (i < nb_numbers - 1)
	{
		next_min = all->max;
		tmp = all->a->first;
		j = 0;
		while (j < all->a->len)
		{
			number = tmp->value;
			if (number > min && number < next_min)
				next_min = number;
			tmp = tmp->next;
			j++;
		}
		min = next_min;
		i++;
	}
	return (min);
}

void	set_utils_variables(t_all *all)
{
	int	nb_numbers;
	int	to_add;
	int	min;
	int	i;

	all->nb_chunks = all->len / OPTI;
	to_add = all->len % OPTI;
	if (to_add || !all->nb_chunks)
		all->nb_chunks++;
	all->median = (int *)malloc(sizeof(int) * all->nb_chunks);
	if (!all->median)
		error(all);
	all->median[all->nb_chunks - 1] = all->max;
	min = all->min;
	i = 0;
	while (i < all->nb_chunks - 1)
	{
		nb_numbers = all->len / all->nb_chunks;
		if (i == 0)
			nb_numbers += (all->len % all->nb_chunks);
		all->median[i] = find_median(all, nb_numbers, min);
		min = all->median[i] + 1;
		i++;
	}
}
