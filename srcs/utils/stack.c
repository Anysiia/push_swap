/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:05:28 by cmorel-a          #+#    #+#             */
/*   Updated: 2021/03/18 15:57:38 by cmorel-a         ###   ########.fr       */
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
	new->prev = stack->last;
	new->next = NULL;
	if (stack->last)
		stack->last->next = new;
	else
		stack->first = new;
	stack->last = new;
	stack->len++;
	return (EXIT_SUCCESS);
}

int	push_front_number(t_stack *stack, int value)
{
	t_number	*new;

	new = malloc(sizeof(t_number));
	if (!new)
		return (EXIT_FAILURE);
	new->value = value;
	new->next = stack->first;
	new->prev = NULL;
	if (stack->first)
		stack->first->prev = new;
	else
		stack->last = new;
	stack->first = new;
	stack->len++;
	return (EXIT_SUCCESS);
}

int	remove_back_number(t_stack *stack)
{
	t_number	*tmp;

	tmp = stack->last;
	if (!tmp)
		return (EXIT_FAILURE);
	stack->last = tmp->prev;
	if (stack->last)
		stack->last->next = NULL;
	else
		stack->first = NULL;
	free(tmp);
	stack->len--;
	return (EXIT_SUCCESS);
}

int	remove_front_number(t_stack *stack)
{
	t_number	*tmp;

	tmp = stack->first;
	if (!tmp)
		return (EXIT_FAILURE);
	stack->first = tmp->next;
	if (stack->first)
		stack->first->next = NULL;
	else
		stack->last = NULL;
	free(tmp);
	stack->len--;
	return (EXIT_SUCCESS);
}

void	free_stack(t_stack **to_free)
{
	t_number	*tmp;
	t_number	*next;

	next = (*to_free)->first;
	while (next)
	{
		tmp = next;
		next = tmp->next;
		free(tmp);
	}
	(*to_free)->first = NULL;
	(*to_free)->last = NULL;
	free(*to_free);
	*to_free = NULL;
}
