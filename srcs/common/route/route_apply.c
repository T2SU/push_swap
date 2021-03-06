/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   route_apply.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 02:02:47 by smun              #+#    #+#             */
/*   Updated: 2021/06/21 08:46:30 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include <unistd.h>

static void	step_route(t_route *pr, int step_a, int step_b, const char *str)
{
	pr->distance_a += step_a;
	pr->distance_b += step_b;
	print(str);
	print("\n");
}

static int	get_number_positive(int num)
{
	if (num > 0)
		return (kPositive);
	if (num < 0)
		return (kNegative);
	return (kZero);
}

void		print_instructions_by_route(t_route route)
{
	int		a_positive;
	int		b_positive;

	while (TRUE)
	{
		a_positive = get_number_positive(route.distance_a);
		b_positive = get_number_positive(route.distance_b);
		if (a_positive == kZero && b_positive == kZero)
			break ;
		if (a_positive == kNegative && b_positive == kNegative)
			step_route(&route, +1, +1, "rrr");
		else if (a_positive == kPositive && b_positive == kPositive)
			step_route(&route, -1, -1, "rr");
		else if (a_positive == kNegative)
			step_route(&route, +1, 0, "rra");
		else if (a_positive == kPositive)
			step_route(&route, -1, 0, "ra");
		else if (b_positive == kNegative)
			step_route(&route, 0, +1, "rrb");
		else if (b_positive == kPositive)
			step_route(&route, 0, -1, "rb");
	}
}

void		apply_distance_to_list(t_list *list, int distance)
{
	while (distance != 0)
	{
		if (distance > 0)
		{
			list_rotate(list);
			distance--;
		}
		if (distance < 0)
		{
			list_reverse_rotate(list);
			distance++;
		}
	}
}
