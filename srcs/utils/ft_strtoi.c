/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 11:16:59 by cmorel-a          #+#    #+#             */
/*   Updated: 2021/03/22 10:46:04 by cmorel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/global.h"

static int	check_overflow(int init, int to_add, int sign, int *is_overflow)
{
	if (init > OVF_INT)
	{
		*is_overflow = 1;
		if (sign == 1)
			return (INT_MAX);
		if (sign == -1)
			return (INT_MIN);
	}
	if (init == OVF_INT)
	{
		if (sign == 1 && to_add > 7)
		{
			*is_overflow = 1;
			return (INT_MAX);
		}
		if (sign == -1 && to_add > 8)
		{
			*is_overflow = 1;
			return (INT_MIN);
		}
	}
	return (-1);
}

int	ft_strtoi(const char *str, int *is_overflow)
{
	int	tmp;
	int	sign;
	int	overflow;

	tmp = 0;
	sign = 1;
	overflow = -1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		if (tmp >= OVF_INT)
			overflow = check_overflow(tmp, *str - 48, sign, is_overflow);
		if (overflow != -1)
			return (overflow);
		tmp = tmp * 10 + (*str - 48);
		str++;
	}
	return (tmp * sign);
}
