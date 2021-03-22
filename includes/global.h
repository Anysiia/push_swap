/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 12:01:36 by cmorel-a          #+#    #+#             */
/*   Updated: 2021/03/22 11:21:28 by cmorel-a         ###   ########.fr       */
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
int		push_back_instruction(t_ope_list *ope, char *instruction);
void	free_list(t_ope_list **to_free);
void	print_operation_list(t_all *all);
void	print_stacks(t_all *all);
int		push_back_number(t_stack *stack, int value);
int		push_front_number(t_stack *stack, int value);
int		remove_back_number(t_stack *stack);
int		remove_front_number(t_stack *stack);
void	free_stack(t_stack **to_free);
int		ft_strtoi(const char *number, int *is_overflow);
int		check_args(int ac, char **av, t_all *all);

/*
instructions
*/
int		swap_a(t_all *all);
int		swap_b(t_all *all);
int		swap_all(t_all *all);
int		push_a(t_all *all);
int		push_b(t_all *all);
int		rotate_a(t_all *all);
int		rotate_b(t_all *all);
int		rotate_all(t_all *all);
int		reverse_rotate_a(t_all *all);
int		reverse_rotate_b(t_all *all);
int		reverse_rotate_all(t_all *all);

/*
Checker
*/
int		get_instruction(t_all *all);
int		execute_all_instruction(t_all *all);

/*
push_swap
*/

#endif
