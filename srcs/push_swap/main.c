/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 14:40:50 by cmorel-a          #+#    #+#             */
/*   Updated: 2021/03/18 16:56:15 by cmorel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/global.h"

int	main(int ac, char **av)
{
	int		ret;
	t_all	tmp;

	if (ac == 1)
		return (EXIT_SUCCESS);
	init_all(&tmp);
	ret = check_args(ac, av, &tmp);
	if (ret)
		return (error(&tmp));
	print_stacks(&tmp);
	free_all(&tmp);
	return (EXIT_SUCCESS);
}
