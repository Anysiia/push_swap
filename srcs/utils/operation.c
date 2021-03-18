/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:05:28 by cmorel-a          #+#    #+#             */
/*   Updated: 2021/03/18 15:17:17 by cmorel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/global.h"

int	push_back_instruction(t_ope_list *ope, char *instruction)
{
	t_op	*new;

	new = malloc(sizeof(t_number));
	if (!new)
		return (EXIT_FAILURE);
	new->data = instruction;
	new->prev = ope->last;
	new->next = NULL;
	if (ope->last)
		ope->last->next = new;
	else
		ope->first = new;
	ope->last = new;
	ope->len++;
	return (EXIT_SUCCESS);
}

void	free_list(t_ope_list **to_free)
{
	t_op	*tmp;
	t_op	*next;

	next = (*to_free)->first;
	while (next)
	{
		tmp = next;
		ft_freestr(&tmp->data);
		next = tmp->next;
		free(tmp);
	}
	(*to_free)->first = NULL;
	(*to_free)->last = NULL;
	*to_free = NULL;
}

void	print_operation_list(t_all *all)
{
	t_op	*tmp;

	tmp = all->op->first;
	while (tmp)
	{
		ft_putstr(tmp->data);
		tmp = tmp->next;
		ft_putchar('\n');
	}
}

void	print_stacks(t_all *all)
{
	t_number	*a;
	t_number	*b;

	a = all->a->first;
	b = all->b->first;
	while (a || b)
	{
		if (a)
		{
			ft_putnbr(a->value);
			a = a->next;
		}
		ft_putstr("		");
		if (b)
		{
			ft_putnbr(b->value);
			b = b->next;
		}
		ft_putchar('\n');
	}
}
