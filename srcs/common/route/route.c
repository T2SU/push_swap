/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   route.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 02:45:57 by smun              #+#    #+#             */
/*   Updated: 2021/06/13 18:59:51 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include <stdio.h>

static int		get_fastest_distance(t_list *list, int value)
{
	int			forward_value;
	int			backward_value;
	int			i;

	i = 0;
	while (i < list->length)
	{
		forward_value = list_get(list, i);
		backward_value = list_get(list, -i);
		if (forward_value == value)
			return (i);
		if (backward_value == value)
			return (-i);
		i++;
	}
	return (0);
}

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

static int		get_highest_number(t_list *list, int basis)
{
	int			highest;
	int			i;
	int			num;

	highest = INT_MIN;
	i = 0;
	while (i < list->length)
	{
		num = list_get(list, i++);
		if (basis < num)
			continue;
		if (highest < num)
			highest = num;
	}
	return (highest);
}

/*
** flag == 0 means   'value' is able to get by index 0.
*/

static int		calculate_route_for_proper_index(t_list *list, int value)
{
	const int	flag = retrieve_number_flag(list, value);
	int			destination;
	
	if ((flag & kHasHigher) && (flag & kHasLower))
		destination = get_highest_number(list, value);
	else if ((flag & kHasHigher) || (flag & kHasLower))
		destination = get_highest_number(list, INT_MIN);
	else
		return (0);
	return (get_fastest_distance(list, destination));
}
	
t_route			calculate_route(t_list *list_a, t_list *list_b, int value)
{
	t_route		route;

	route.distance_a = get_fastest_distance(list_a, value);
	route.distance_b = calculate_route_for_proper_index(list_b, value);
	if (ft_isneg(route.distance_a) ^ ft_isneg(route.distance_b))
		route.total_cost = route.distance_a - route.distance_b;
	else
		route.total_cost = ft_max(route.distance_a, route.distance_b);
	route.total_cost = ft_abs(route.total_cost);
	return (route);
}
