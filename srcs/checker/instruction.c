/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 17:05:40 by cmorel-a          #+#    #+#             */
/*   Updated: 2021/05/25 10:33:30 by cmorel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/global.h"

static int	is_instruction(char	*to_test)
{
	int			i;
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

void	get_instruction(t_all *all)
{
	char	*line;
	int		ret;

	line = NULL;
	while (get_next_line(STDIN, &line) == 1)
	{
		ret = is_instruction(line);
		if (ret == EXIT_FAILURE)
		{
			ft_freestr(&line);
			error(all);
		}
		ret = push_back_instruction(all->op, line);
		if (ret == EXIT_FAILURE)
		{
			ft_freestr(&line);
			error(all);
		}
		ft_freestr(&line);
	}
	if (line)
		ft_freestr(&line);
}

void	execute_all_instruction(t_all *all)
{
	t_op	*list;

	list = all->op->first;
	while (list)
	{
		execute_instruction(all, list->data, 0);
		list = list->next;
	}
}
