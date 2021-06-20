/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   route.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 02:45:57 by smun              #+#    #+#             */
/*   Updated: 2021/06/21 08:45:25 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include <stdio.h>

static int		retrieve_number_flag(t_list *list, int basis)
{
	int			flag;
	int			i;

	flag = 0;
	i = 0;
	while (i < list->length)
	{
		if (list_get(list, i) > basis)
			flag |= kHasHigher;
		if (list_get(list, i) < basis)
			flag |= kHasLower;
		i++;
	}
	return (flag);
}

/*
** flag == 0 means   'value' is able to get by index 0.
*/

static int		calculate_for_proper_index(t_list *list, int value, int order)
{
	const int	flag = retrieve_number_flag(list, value);
	int			destination;

	if ((flag & kHasHigher) && (flag & kHasLower))
	{
		if (order == kDescending)
			destination = list_get_highest_number(list, value);
		else
			destination = list_get_lowest_number(list, value);
	}
	else if ((flag & kHasHigher) || (flag & kHasLower))
	{
		if (order == kDescending)
			destination = list_get_highest_number(list, INT_MAX);
		else
			destination = list_get_lowest_number(list, INT_MIN);
	}
	else
		return (0);
	return (list_get_fastest_distance(list, destination));
}

static t_route	new_route(int a_route, int b_route, int total_cost)
{
	t_route		ret;

	ret.distance_a = a_route;
	ret.distance_b = b_route;
	ret.total_cost = total_cost;
	return (ret);
}

/*
**  A's sign == B's sign
**    -->  max(abs(a), abs(b))
**
**  A's sign != B's sign
**    -->  abs(a - b)
*/

t_route			calculate_route(t_list *a, t_list *b, int value, int dir)
{
	int			orig_route;
	t_list		*orig_list;
	int			dest_route;
	t_list		*dest_list;
	int			total_cost;

	orig_list = dir == A_TO_B ? a : b;
	dest_list = dir == A_TO_B ? b : a;
	orig_route = list_get_fastest_distance(orig_list, value);
	if (dir == A_TO_B)
		dest_route = calculate_for_proper_index(dest_list, value, kDescending);
	else
		dest_route = calculate_for_proper_index(dest_list, value, kAscending);
	if (ft_isneg(orig_route) ^ ft_isneg(dest_route))
		total_cost = ft_abs(orig_route - dest_route);
	else
		total_cost = ft_max(ft_abs(orig_route), ft_abs(dest_route));
	if (dir == A_TO_B)
		return (new_route(orig_route, dest_route, total_cost));
	return (new_route(dest_route, orig_route, total_cost));
}
