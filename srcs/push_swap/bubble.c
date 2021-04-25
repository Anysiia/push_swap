/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 10:38:06 by cmorel-a          #+#    #+#             */
/*   Updated: 2021/04/25 10:38:29 by cmorel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/global.h"

static void	bb_sort(t_all *all)
{
	int			i;
	int			j;
	t_number	*tmp;

	i = 1;
	while (i < all->a->len)
	{
		if (!is_sort(all))
			return ;
		tmp = all->a->first;
		j = 1;
		while (j < all->a->len)
		{
			if (!is_sort(all))
				return ;
			if (tmp->value > tmp->next->value)
				swap_a(all, 1);
			rotate_a(all, 1);
			tmp = all->a->first;
			j++;
		}
		rotate_a(all, 1);
		i++;
	}
}
