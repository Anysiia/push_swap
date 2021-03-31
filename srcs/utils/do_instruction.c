/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_instruction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 11:24:11 by cmorel-a          #+#    #+#             */
/*   Updated: 2021/03/31 18:03:51 by cmorel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/global.h"

void	execute_instruction(t_all *all, char *instruction, int print)
{
	if (!ft_strcmp("sa", instruction))
		swap_a(all, print);
	else if (!ft_strcmp("sb", instruction))
		swap_b(all, print);
	else if (!ft_strcmp("ss", instruction))
		swap_all(all, print);
	else if (!ft_strcmp("pa", instruction))
		push_a(all, print);
	else if (!ft_strcmp("pb", instruction))
		push_b(all, print);
	else if (!ft_strcmp("ra", instruction))
		rotate_a(all, print);
	else if (!ft_strcmp("rb", instruction))
		rotate_b(all, print);
	else if (!ft_strcmp("rr", instruction))
		rotate_all(all, print);
	else if (!ft_strcmp("rra", instruction))
		reverse_rotate_a(all, print);
	else if (!ft_strcmp("rrb", instruction))
		reverse_rotate_b(all, print);
	else if (!ft_strcmp("rrr", instruction))
		reverse_rotate_all(all, print);
	else
		error(all);
}
