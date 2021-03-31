/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_case.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 15:42:37 by cmorel-a          #+#    #+#             */
/*   Updated: 2021/03/31 18:46:39 by cmorel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/global.h"

void	three_case(t_all *all)
{
	int	value1;
	int	value2;
	int	value3;

	if (all->a->len != 3)
		return ;
	value1 = all->a->first->value;
	value2 = all->a->first->next->value;
	value3 = all->a->first->next->next->value;
	if (value1 > value2 && value2 < value3 && value1 < value3)
		return (swap_a(all, 1));
	else if (value1 > value2 && value1 > value3 && value2 < value3)
		return (rotate_a(all, 1));
	else if (value1 < value2 && value1 > value3 && value2 > value3)
		return (reverse_rotate_a(all, 1));
	swap_a(all, 1);
	if (value1 > value2 && value1 > value3 && value2 > value3)
		reverse_rotate_a(all, 1);
	else
		rotate_a(all, 1);
}
