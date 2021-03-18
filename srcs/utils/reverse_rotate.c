/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 16:18:05 by cmorel-a          #+#    #+#             */
/*   Updated: 2021/03/18 16:25:19 by cmorel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/global.h"

int	reverse_rotate_a(t_all *all)
{
	return (EXIT_SUCCESS);
}

int	reverse_rotate_b(t_all *all)
{
	return (EXIT_SUCCESS);
}

int	reverse_rotate_all(t_all *all)
{
	int	ret;

	ret = reverse_rotate_a(all);
	if (ret == EXIT_FAILURE)
		return (EXIT_FAILURE);
	ret = reverse_rotate_b(all);
	if (ret == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}