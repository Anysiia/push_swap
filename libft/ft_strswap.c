/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 10:01:16 by cmorel-a          #+#    #+#             */
/*   Updated: 2021/02/19 10:01:59 by cmorel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strswap(char **s1, char **s2)
{
	char	*tmp;

	if (!(*s1) || !(*s2))
		return ;
	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}
