/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 12:01:36 by cmorel-a          #+#    #+#             */
/*   Updated: 2021/03/31 15:40:46 by cmorel-a         ###   ########.fr       */
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
int		is_sort(t_all *all);
int		execute_instruction(t_all *all, char *instruction, int print);

/*
instructions
*/
int		swap_a(t_all *all, int print);
int		swap_b(t_all *all, int print);
int		swap_all(t_all *all, int print);
int		push_a(t_all *all, int print);
int		push_b(t_all *all, int print);
int		rotate_a(t_all *all, int print);
int		rotate_b(t_all *all, int print);
int		rotate_all(t_all *all, int print);
int		reverse_rotate_a(t_all *all, int print);
int		reverse_rotate_b(t_all *all, int print);
int		reverse_rotate_all(t_all *all, int print);

/*
Checker
*/
int		get_instruction(t_all *all);
int		execute_all_instruction(t_all *all);

/*
push_swap
*/
int		select_algo(t_all *all);
int		three_case(t_all *all);
int		five_case(t_all *all);
int		insert_sort(t_all *all);
int		quick_sort(t_all *all);

int		find_smaller_number_position(t_stack *stack, int *smaller);
int		find_larger_number_position(t_stack *stack, int *larger);
int		ra_rra_n_times(t_all *all, int n);
int		rb_rrb_n_times(t_all *all, int n);

#endif
