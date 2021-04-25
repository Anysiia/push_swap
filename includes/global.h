/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 12:01:36 by cmorel-a          #+#    #+#             */
/*   Updated: 2021/04/25 10:30:02 by cmorel-a         ###   ########.fr       */
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
void	init_all(t_all *all);
void	free_all(t_all *all);
void	error(t_all *all);
int		push_back_instruction(t_ope_list *ope, char *instruction);
void	free_list(t_ope_list **to_free);
void	print_operation_list(t_all *all);
void	print_stacks(t_all *all);
int		push_back_number(t_stack *stack, int value);
void	free_stack(t_stack **to_free);
int		ft_strtoi(const char *number, int *is_overflow);
void	check_args(int ac, char **av, t_all *all);
int		is_sort(t_all *all);
int		is_sort_stack(t_stack *stack);
void	execute_instruction(t_all *all, char *instruction, int print);

/*
instructions
*/
void	swap_a(t_all *all, int print);
void	swap_b(t_all *all, int print);
void	swap_all(t_all *all, int print);
void	push_a(t_all *all, int print);
void	push_b(t_all *all, int print);
void	rotate_a(t_all *all, int print);
void	rotate_b(t_all *all, int print);
void	rotate_all(t_all *all, int print);
void	reverse_rotate_a(t_all *all, int print);
void	reverse_rotate_b(t_all *all, int print);
void	reverse_rotate_all(t_all *all, int print);

/*
Checker
*/
void	get_instruction(t_all *all);
void	execute_all_instruction(t_all *all);

/*
push_swap
*/
void	sort(t_all *all, int nb_chunks);
int		*get_limit_values(t_all *all, t_stack *stack, int parts);
int		find_smaller_number_position(t_stack *stack, int *smaller);
int		find_larger_number_position(t_stack *stack, int *larger);
void	ra_rra(t_all *all, int position);
void	rb_rrb(t_all *all, int position);
void	push_larger_to_b(t_all *all);


#endif
