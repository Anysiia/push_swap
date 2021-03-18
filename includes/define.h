/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmorel-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 12:47:34 by cmorel-a          #+#    #+#             */
/*   Updated: 2021/03/18 13:08:01 by cmorel-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H
# include "global.h"

# define STDIN 0
# define STDOUT 1
# define STDERR 2

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
	t_number	*last;
}	t_stack;

typedef struct s_list
{
	char			*data;
	struct s_list	*next;
}	t_list;

typedef struct s_ope_list
{
	t_list	*first;
	t_list	*last;
}	t_ope_list;

typedef struct s_all
{
	t_stack		*a;
	t_stack		*b;
	t_ope_list	*op;
}	t_all;

#endif
