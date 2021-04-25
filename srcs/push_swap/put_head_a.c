/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_head_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 15:10:32 by cmorel-a          #+#    #+#             */
/*   Updated: 2021/04/25 15:16:48 by cmorel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/global.h"

void	put_head_a(t_all *all)
{
	int	pos;
	int	small;

	pos = find_smaller_number_position(all->a, &small);
	ra_rra(all, pos);
}
