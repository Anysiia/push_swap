/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 11:09:10 by cmorel-a          #+#    #+#             */
/*   Updated: 2021/01/13 14:43:15 by cmorel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*s2;
	size_t	len;

	len = 0;
	if (!s || !f)
		return (NULL);
	while (s[len])
		len++;
	s2 = (char *)malloc(sizeof(*s2) * (len + 1));
	if (!s2)
		return (NULL);
	len = 0;
	while (s[len] && f)
	{
		s2[len] = f(len, s[len]);
		len++;
	}
	s2[len] = '\0';
	return (s2);
}
