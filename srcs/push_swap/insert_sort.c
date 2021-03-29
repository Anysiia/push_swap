/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 16:31:17 by cmorel-a          #+#    #+#             */
/*   Updated: 2021/03/29 18:05:30 by cmorel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/global.h"

int	go_to_b(t_all *all)
{
	int			ret;
	int			first_value;
	t_number	*tmp;

	tmp = all->a->first;
	first_value = tmp->value;
	while (tmp->next->value != first_value)
	{
		if (tmp->value > tmp->next->value)
		{
			ret = push_b(all, 1);
			if (ret)
				return (ret);
		}
		else
		{
			ret = rotate_a(all, 1);
			if (ret)
				return (ret);
		}
	}
	return (EXIT_SUCCESS);
}

int	insert_sort(t_all *all)
{
	int	ret;

	ret = go_to_b(all);
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
