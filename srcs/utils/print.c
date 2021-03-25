/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 11:17:16 by cmorel-a          #+#    #+#             */
/*   Updated: 2021/03/25 12:11:18 by cmorel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/global.h"

void	print_operation_list(t_all *all)
{
	t_op	*tmp;

	tmp = all->op->first;
	while (tmp)
	{
		ft_putstr(tmp->data);
		tmp = tmp->next;
	}
}

void	print_stacks(t_all *all)
{
	t_number	*a;
	t_number	*b;
	int			i;

	a = all->a->first;
	b = all->b->first;
	ft_putstr("Stack a: ");
	i = 0;
	while (i < all->a->len)
	{
		ft_putnbr(a->value);
		ft_putchar(' ');
		a = a->next;
		i++;
	}
	ft_putstr("\nStack b: ");
	i = 0;
	while (i < all->b->len)
	{
		ft_putnbr(b->value);
		ft_putchar(' ');
		b = b->next;
		i++;
	}
	ft_putchar('\n');
}
