/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_instruction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 11:24:11 by cmorel-a          #+#    #+#             */
/*   Updated: 2021/03/25 11:24:30 by cmorel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/global.h"

int	execute_instruction(t_all *all, char *instruction, int print)
{
	if (!ft_strcmp("sa", instruction))
		return (swap_a(all, print));
	if (!ft_strcmp("sb", instruction))
		return (swap_b(all, print));
	if (!ft_strcmp("ss", instruction))
		return (swap_all(all, print));
	if (!ft_strcmp("pa", instruction))
		return (push_a(all, print));
	if (!ft_strcmp("pb", instruction))
		return (push_b(all, print));
	if (!ft_strcmp("ra", instruction))
		return (rotate_a(all, print));
	if (!ft_strcmp("rb", instruction))
		return (rotate_b(all, print));
	if (!ft_strcmp("rr", instruction))
		return (rotate_all(all, print));
	if (!ft_strcmp("rra", instruction))
		return (reverse_rotate_a(all, print));
	if (!ft_strcmp("rrb", instruction))
		return (reverse_rotate_b(all, print));
	if (!ft_strcmp("rrr", instruction))
		return (reverse_rotate_all(all, print));
	return (EXIT_FAILURE);
}
