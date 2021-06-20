/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 14:02:28 by smun              #+#    #+#             */
/*   Updated: 2021/06/21 06:24:09 by smun             ###   ########.fr       */
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
**      srcs/checker/action.c
**  ===========================================
*/

t_instruction	parse_instruction(const char *input);
void			do_action(t_list *a, t_list *b, t_instruction ins);
t_bool			action_from_stdin(t_list *list_a, t_list *list_b);

/*
**  ===========================================
**      srcs/checker/check.c
**  ===========================================
*/

void			check_is_sorted(t_list *a, t_list *b, int init_element_count);

#endif
