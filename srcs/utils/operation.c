/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 12:05:28 by cmorel-a          #+#    #+#             */
/*   Updated: 2021/03/25 11:18:39 by cmorel-a         ###   ########.fr       */
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
	free(*to_free);
	*to_free = NULL;
}
