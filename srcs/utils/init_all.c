/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:05:28 by cmorel-a          #+#    #+#             */
/*   Updated: 2021/03/31 17:44:29 by cmorel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/global.h"

void	init_all(t_all *all)
{
	all->a = malloc(sizeof(t_stack));
	if (!all->a)
		error(all);
	all->a->first = NULL;
	all->b = malloc(sizeof(t_stack));
	if (!all->b)
		error(all);
	all->a->len = 0;
	all->b->first = NULL;
	all->b->len = 0;
	all->op = malloc(sizeof(t_ope_list));
	if (!all->op)
		error(all);
	all->op->first = NULL;
	all->op->last = NULL;
	all->op->len = 0;
}

void	free_all(t_all *all)
{
	if (all->a)
		free_stack(&all->a);
	if (all->b)
		free_stack(&all->b);
	if (all->op)
		free_list(&all->op);
}

void	error(t_all *all)
{
	ft_putstr_fd("Error\n", STDERR);
	free_all(all);
	exit(EXIT_FAILURE);
}
