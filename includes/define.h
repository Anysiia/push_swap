/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 12:47:34 by cmorel-a          #+#    #+#             */
/*   Updated: 2021/04/25 16:26:34 by cmorel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H
# include "global.h"

# define STDIN 0
# define STDOUT 1
# define STDERR 2
# define NB_OP 11

typedef struct s_info
{
	int		value_top;
	int		value_bottom;
	int		pos_top;
	int		pos_bottom;
	int		pos_b;
}	t_info;

typedef struct s_number
{
	int				value;
	struct s_number	*prev;
	struct s_number	*next;
}	t_number;

typedef struct s_stack
{
	int			len;
	t_number	*first;
}	t_stack;

typedef struct s_op
{
	char		*data;
	struct s_op	*next;
	struct s_op	*prev;
}	t_op;

typedef struct s_ope_list
{
	int		len;
	t_op	*first;
	t_op	*last;
}	t_ope_list;

typedef struct s_all
{
	t_stack		*a;
	t_stack		*b;
	t_ope_list	*op;
}	t_all;

#endif
