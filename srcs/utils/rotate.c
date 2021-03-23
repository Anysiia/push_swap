/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 16:15:28 by cmorel-a          #+#    #+#             */
/*   Updated: 2021/03/23 12:38:36 by cmorel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/global.h"

int	rotate_a(t_all *all)
{
	if (all->a->len > 0)
		all->a->first = all->a->first->next;
	return (EXIT_SUCCESS);
}

int	rotate_b(t_all *all)
{
	if (all->b->len > 0)
		all->b->first = all->b->first->next;
	return (EXIT_SUCCESS);
}

int	rotate_all(t_all *all)
{
	int	ret;

	ret = rotate_a(all);
	ret = rotate_b(all);
	return (EXIT_SUCCESS);
}
