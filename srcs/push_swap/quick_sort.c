/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 12:20:05 by cmorel-a          #+#    #+#             */
/*   Updated: 2021/04/25 15:35:19 by cmorel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/global.h"

static void	fill_b(t_all *all, int nb, int i)
{
	while (nb)
	{
		if (all->a->first->value <= all->median[i])
			push_b(all, 1);
		else
			rotate_a(all, 1);
		nb--;
	}
}

static void	move_a(t_all *all, int i)
{
	int	rotate_up;
	int	rotate_down;

	if (i != 0 && i != all->nb_chunks - 1)
	{
		rotate_up = all->median[i];
		rotate_down = all->len - all->median[i];
		if (rotate_up < rotate_down)
		{
			while (rotate_up > 0)
			{
				rotate_a(all, 1);
				rotate_up--;
			}
		}
		else
		{
			while (rotate_down > 0)
			{
				reverse_rotate_a(all, 1);
				rotate_down--;
			}
		}
	}
}

static void	replace_a(t_all *all, int i, int *remain)
{
	while (i < (all->nb_chunks - 1) && *remain)
	{
		rotate_a(all, 1);
		(*remain)--;
	}
}

static void	put_head_a(t_all *all)
{
	int	pos;
	int	small;

	pos = find_smaller_number_position(all->a, &small);
	ra_rra(all, pos);
}

void	quick_sort(t_all *all)
{
	int	i;
	int	nb;
	int	remain;

	i = 0;
	set_utils_variables(all);
	nb = all->len;
	while (i < all-> nb_chunks)
	{
		remain = 0;
		fill_b(all, nb, i);
		move_a(all, i);
		fill_a(all, &remain);
		replace_a(all, i, &remain);
		nb = all->len - all->median[i];
		i++;
	}
	put_head_a(all);
}
