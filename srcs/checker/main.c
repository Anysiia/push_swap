/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 11:59:31 by cmorel-a          #+#    #+#             */
/*   Updated: 2021/03/31 17:46:57 by cmorel-a         ###   ########.fr       */
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
	check_args(ac, av, &tmp);
	get_instruction(&tmp);
	execute_all_instruction(&tmp);
	ret = is_sort(&tmp);
	if (ret)
		ft_putstr("KO\n");
	else
		ft_putstr("OK\n");
	free_all(&tmp);
	return (EXIT_SUCCESS);
}
