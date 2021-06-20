/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 14:02:28 by smun              #+#    #+#             */
/*   Updated: 2021/06/21 05:40:12 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "common.h"

enum			e_target
{
	kStackA = 1 << 0,
	kStackB = 1 << 1
};

enum			e_instruction
{
	kPush,
	kSwap,
	kRotate,
	kReverseRotate
};

typedef struct	s_instruction
{
	int			target;
	int			type;
}				t_instruction;

/*
**  ===========================================
**      srcs/checker/reader.c
**  ===========================================
*/

void			do_action(t_list *a, t_list *b, t_instruction ins);
t_bool			action_from_stdin(t_list *list_a, t_list *list_b);

#endif
