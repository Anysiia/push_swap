/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 17:05:40 by cmorel-a          #+#    #+#             */
/*   Updated: 2021/03/18 17:54:14 by cmorel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/global.h"

static int	is_instruction(char	*to_test)
{
	int			i;
	int			len;
	static char	*operation_list[] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb",
		"rr", "rra", "rrb", "rrr"};

	i = 0;
	while (i < NB_OP)
	{
		if (!ft_strcmp(to_test, operation_list[i]))
			return (EXIT_SUCCESS);
		i++;
	}
	return (EXIT_FAILURE);
}

int	get_instruction(t_all *all)
{
	char	*line;
	int		ret;

	while (get_next_line(STDIN, &line) == 1)
	{
		ret = is_instruction(line);
		if (ret == EXIT_FAILURE)
			return (EXIT_FAILURE);
		ret = push_back_instruction(all->op, line);
		if (ret == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	execute_instruction(t_all *all, char *instruction)
{
	if (!ft_strcmp("sa", instruction))
		return (swap_a(all));
	if (!ft_strcmp("sb", instruction))
		return (swap_b(all));
	if (!ft_strcmp("ss", instruction))
		return (swap_all(all));
	if (!ft_strcmp("pa", instruction))
		return (push_a(all));
	if (!ft_strcmp("pb", instruction))
		return (push_b(all));
	if (!ft_strcmp("ra", instruction))
		return (rotate_a(all));
	if (!ft_strcmp("rb", instruction))
		return (rotate_b(all));
	if (!ft_strcmp("rr", instruction))
		return (rotate_all(all));
	if (!ft_strcmp("rra", instruction))
		return (reverse_rotate_a(all));
	if (!ft_strcmp("rrb", instruction))
		return (reverse_rotate_b(all));
	if (!ft_strcmp("rrr", instruction))
		return (reverse_rotate_all(all));
	return (EXIT_FAILURE);
}
