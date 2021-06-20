/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 03:25:13 by smun              #+#    #+#             */
/*   Updated: 2021/06/21 07:18:36 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

static int			determine_target(const char *input)
{
	int				ret;

	ret = 0;
	if (!ft_strcmp(input, "rr") || !ft_strcmp(input, "ra") ||
		!ft_strcmp(input, "rrr") || !ft_strcmp(input, "rra") ||
		!ft_strcmp(input, "ss") || !ft_strcmp(input, "sa") ||
		!ft_strcmp(input, "pa"))
		ret |= kStackA;
	if (!ft_strcmp(input, "rr") || !ft_strcmp(input, "rb") ||
		!ft_strcmp(input, "rrr") || !ft_strcmp(input, "rrb") ||
		!ft_strcmp(input, "ss") || !ft_strcmp(input, "sb") ||
		!ft_strcmp(input, "pb"))
		ret |= kStackB;
	return (ret);
}

t_instruction		parse_instruction(const char *input)
{
	t_instruction	ret;

	ret.target = determine_target(input);
	if (!ft_strcmp(input, "rr") ||
		!ft_strcmp(input, "ra") ||
		!ft_strcmp(input, "rb"))
		ret.type = kRotate;
	else if (!ft_strcmp(input, "rrr") ||
			!ft_strcmp(input, "rra") ||
			!ft_strcmp(input, "rrb"))
		ret.type = kReverseRotate;
	else if (!ft_strcmp(input, "sa") ||
			!ft_strcmp(input, "sb") ||
			!ft_strcmp(input, "ss"))
		ret.type = kSwap;
	else if (!ft_strcmp(input, "pa") ||
			!ft_strcmp(input, "pb"))
		ret.type = kPush;
	return (ret);
}

void				do_action(t_list *a, t_list *b, t_instruction ins)
{
	if (ins.type == kRotate && (ins.target & kStackA))
		list_rotate(a);
	if (ins.type == kRotate && (ins.target & kStackB))
		list_rotate(b);
	if (ins.type == kReverseRotate && (ins.target & kStackA))
		list_reverse_rotate(a);
	if (ins.type == kReverseRotate && (ins.target & kStackB))
		list_reverse_rotate(b);
	if (ins.type == kSwap && (ins.target & kStackA))
		list_swap(a, NULL);
	if (ins.type == kSwap && (ins.target & kStackB))
		list_swap(b, NULL);
	if (ins.type == kPush && (ins.target & kStackA))
		list_push(a, b, B_TO_A);
	else if (ins.type == kPush && (ins.target & kStackB))
		list_push(a, b, A_TO_B);
}

t_bool				action_from_stdin(t_list *list_a, t_list *list_b)
{
	char			*line;
	int				status;
	t_instruction	ins;

	status = get_next_line(STDIN_FILENO, &line);
	if (status == -1)
		raise_error("failed on gnl");
	ins = parse_instruction(line);
	if (status == kReturnFoundLine || ft_strlen(line) > 0)
		if (ins.target == 0)
			raise_error_description("unknown instruction", line);
	free(line);
	do_action(list_a, list_b, ins);
	return (status == kReturnFoundLine);
}
