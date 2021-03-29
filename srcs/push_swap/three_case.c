/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_case.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 15:42:37 by cmorel-a          #+#    #+#             */
/*   Updated: 2021/03/29 16:05:26 by cmorel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/global.h"

int	three_case(t_all *all)
{
	int	value1;
	int	value2;
	int	value3;
	int	ret;

	if (all->a->len != 3)
		return (2);
	value1 = all->a->first->value;
	value2 = all->a->first->next->value;
	value3 = all->a->first->next->next->value;
	if (value1 > value2 && value2 < value3 && value1 < value3)
		return (swap_a(all, 1));
	else if (value1 > value2 && value1 > value3 && value2 < value3)
		return (rotate_a(all, 1));
	else if (value1 < value2 && value1 > value3 && value2 > value3)
		return (reverse_rotate_a(all, 1));
	ret = swap_a(all, 1);
	if (ret)
		return (ret);
	if (value1 > value2 && value1 > value3 && value2 > value3)
		return (reverse_rotate_a(all, 1));
	else
		return (rotate_a(all, 1));
}
