/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 16:31:17 by cmorel-a          #+#    #+#             */
/*   Updated: 2021/03/29 16:50:02 by cmorel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/global.h"

int	insert_sort(t_all *all)
{
	int	ret;

	while (all->a->len > 3)
	{
		ret = push_b(all, 1);
		if (ret)
			return (ret);
	}
	ret = three_case(all);
	if (ret)
		return (ret);
	while (all->b->len > 0)
	{
		ret = push_a(all, 1);
		if (ret)
			return (ret);
	}
	return (EXIT_SUCCESS);
}
