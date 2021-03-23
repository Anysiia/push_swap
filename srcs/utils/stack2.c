/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:05:28 by cmorel-a          #+#    #+#             */
/*   Updated: 2021/03/23 12:26:36 by cmorel-a         ###   ########.fr       */
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

int	push_front_number(t_stack *stack, int value)
{
	int	ret;

	ret = push_back_number(stack, value);
	if (ret)
		return (EXIT_FAILURE);
	stack->first = stack->first->prev;
	return (EXIT_SUCCESS);
}

int	remove_back_number(t_stack *stack)
{
	t_number	*tmp;

	tmp = stack->first->prev;
	if (!tmp)
		return (EXIT_FAILURE);
	stack->first->prev = stack->first->prev->prev;
	stack->first->prev->prev->next = stack->first;
	free(tmp);
	stack->len--;
	return (EXIT_SUCCESS);
}

int	remove_front_number(t_stack *stack)
{
	stack->first = stack->first->next;
	return (remove_back_number(stack));
}

void	free_stack(t_stack **to_free)
{
	t_number	*tmp;
	t_number	*next;

	next = (*to_free)->first;
	while (next && next->next != (*to_free)->first)
	{
		tmp = next;
		next = tmp->next;
		free(tmp);
	}
	(*to_free)->first = NULL;
	free(*to_free);
	*to_free = NULL;
}
