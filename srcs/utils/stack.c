/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:05:28 by cmorel-a          #+#    #+#             */
/*   Updated: 2021/04/25 11:03:24 by cmorel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/global.h"

int	push_back_number(t_stack *stack, int value)
{
	t_number	*new;

	new = malloc(sizeof(t_number));
	if (!new)
		return (EXIT_FAILURE);
	new->value = value;
	if (!stack->first)
	{
		new->prev = new;
		new->next = new;
		stack->first = new;
	}
	else
	{
		new->next = stack->first;
		new->prev = stack->first->prev;
		stack->first->prev->next = new;
		stack->first->prev = new;
	}
	stack->len++;
	return (EXIT_SUCCESS);
}

void	free_stack(t_stack **to_free)
{
	t_number	*tmp;
	t_number	*current;
	int			i;

	current = (*to_free)->first;
	i = 0;
	while (i < (*to_free)->len)
	{
		tmp = current;
		current = tmp->next;
		free(tmp);
		i++;
	}
	(*to_free)->first = NULL;
	free(*to_free);
	*to_free = NULL;
}
