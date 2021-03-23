/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 16:18:05 by cmorel-a          #+#    #+#             */
/*   Updated: 2021/03/23 12:41:26 by cmorel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/global.h"

int	reverse_rotate_a(t_all *all)
{
	if (all->a->len > 0)
		all->a->first = all->a->first->prev;
	return (EXIT_SUCCESS);
}

int	reverse_rotate_b(t_all *all)
{
	if (all->b->len > 0)
		all->b->first = all->b->first->prev;
	return (EXIT_SUCCESS);
}

int	reverse_rotate_all(t_all *all)
{
	int	ret;

	ret = reverse_rotate_a(all);
	ret = reverse_rotate_b(all);
	return (EXIT_SUCCESS);
}
