/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 11:16:59 by cmorel-a          #+#    #+#             */
/*   Updated: 2021/02/15 16:17:13 by cmorel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_overflow(int init, int to_add, int sign)
{
	if (init > OVF_INT)
	{
		errno = ERANGE;
		if (sign == 1)
			return (INT_MAX);
		if (sign == -1)
			return (INT_MIN);
	}
	if (init == OVF_INT)
	{
		if (sign == 1 && to_add > 7)
		{
			errno = ERANGE;
			return (INT_MAX);
		}
		if (sign == -1 && to_add > 8)
		{
			errno = ERANGE;
			return (INT_MIN);
		}
	}
	return (-1);
}

int	ft_atoi(const char *str)
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
		tmp = tmp * 10 + (*str - 48);
		if (tmp >= OVF_INT)
			overflow = check_overflow(tmp, *str - 48, sign);
		if (overflow != -1)
			return (overflow);
		str++;
	}
	return (tmp * sign);
}
