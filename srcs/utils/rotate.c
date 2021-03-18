/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 16:15:28 by cmorel-a          #+#    #+#             */
/*   Updated: 2021/03/18 16:25:35 by cmorel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/global.h"

int	rotate_a(t_all *all)
{

	return (EXIT_SUCCESS);
}

int	rotate_b(t_all *all)
{

	return (EXIT_SUCCESS);
}

int	rotate_all(t_all *all)
{
	int	ret;

	ret = rotate_a(all);
	if (ret == EXIT_FAILURE)
		return (EXIT_FAILURE);
	ret = rotate_b(all);
	if (ret == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
