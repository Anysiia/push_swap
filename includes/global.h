/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 12:01:36 by cmorel-a          #+#    #+#             */
/*   Updated: 2021/03/18 15:31:52 by cmorel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBAL_H
# define GLOBAL_H
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "define.h"

/*
Utils functions
*/
int		init_all(t_all *all);
void	free_all(t_all *all);
int		error(t_all *all);
int		push_bash_instruction(t_ope_list *ope, char *instruction);
void	free_list(t_ope_list **to_free);
void	print_operation_list(t_all *all);
void	print_stacks(t_all *all);
int		push_back_number(t_stack *stack, int value);
int		push_front_number(t_stack *stack, int value);
int		remove_back_number(t_stack *stack);
int		remove_front_number(t_stack *stack);
void	free_stack(t_stack **to_free);
int		check_args(int ac, char **av, t_all *all);

#endif
