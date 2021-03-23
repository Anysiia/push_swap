/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 16:10:22 by cmorel-a          #+#    #+#             */
/*   Updated: 2021/03/23 12:59:27 by cmorel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/global.h"

int	push_a(t_all *all)
{
	int	ret;

	if (all->b->len)
	{
		ret = push_front_number(all->a, all->b->first->value);
		if (ret == EXIT_FAILURE)
			return (EXIT_FAILURE);
		remove_front_number(all->b);
	}
	return (EXIT_SUCCESS);
}

int	push_b(t_all *all)
{
	int	ret;

	if (all->a->len)
	{
		ret = push_front_number(all->b, all->a->first->value);
		if (ret == EXIT_FAILURE)
			return (EXIT_FAILURE);
		remove_front_number(all->a);
	}
	return (EXIT_SUCCESS);
}
