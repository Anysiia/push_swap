/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 17:05:40 by cmorel-a          #+#    #+#             */
/*   Updated: 2021/03/25 17:07:36 by cmorel-a         ###   ########.fr       */
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

int	get_instruction(t_all *all)
{
	char	*line;
	int		ret;

	while (get_next_line(STDIN, &line) == 1)
	{
		ret = is_instruction(line);
		if (ret == EXIT_FAILURE)
		{
			ft_freestr(&line);
			return (EXIT_FAILURE);
		}
		ret = push_back_instruction(all->op, line);
		if (ret == EXIT_FAILURE)
		{
			ft_freestr(&line);
			return (EXIT_FAILURE);
		}
		ft_freestr(&line);
	}
	ft_freestr(&line);
	return (EXIT_SUCCESS);
}

int	execute_all_instruction(t_all *all)
{
	t_op	*list;
	int		ret;

	ft_putstr("\n---Start tri---\n");
	list = all->op->first;
	while (list)
	{
		ret = execute_instruction(all, list->data, 0);
		if (ret)
			return (EXIT_FAILURE);
		ft_putstr("Operation: ");
		ft_putstr(list->data);
		ft_putstr("\n");
		print_stacks(all);
		ft_putstr("\n");
		list = list->next;
	}
	return (EXIT_SUCCESS);
}
