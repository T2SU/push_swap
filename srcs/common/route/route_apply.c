/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   route_apply.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 02:02:47 by smun              #+#    #+#             */
/*   Updated: 2021/06/13 14:07:58 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include <unistd.h>

static void	apply_step(t_route *pr, int step_a, int step_b, const char *str)
{
	pr->distance_a += step_a;
	pr->distance_b += step_b;
	write(STDOUT_FILENO, str, ft_strlen(str));
	write(STDOUT_FILENO, "\n", 1);
}

static int	get_number_positive(int num)
{
	if (num > 0)
		return (POSITIVE);
	if (num < 0)
		return (NEGATIVE);
	return (ZERO);
}

void		apply_route(t_route route)
{
	int		a_positive;
	int		b_positive;

	while (TRUE)
	{
		a_positive = get_number_positive(route.distance_a);
		b_positive = get_number_positive(route.distance_b);
		if (a_positive == ZERO && b_positive == ZERO)
			break ;
		if (a_positive == NEGATIVE && b_positive == NEGATIVE)
			apply_step(&route, +1, +1, "rr");
		else if (a_positive == POSITIVE && b_positive == POSITIVE)
			apply_step(&route, -1, -1, "rrr");
		else if (a_positive == NEGATIVE)
			apply_step(&route, +1, 0, "ra");
		else if (a_positive == POSITIVE)
			apply_step(&route, -1, 0, "rra");
		else if (b_positive == NEGATIVE)
			apply_step(&route, 0, +1, "rb");
		else if (b_positive == POSITIVE)
			apply_step(&route, 0, -1, "rrb");
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
