/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   navigator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 01:50:31 by smun              #+#    #+#             */
/*   Updated: 2021/06/30 10:26:01 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

static void	make_targets(t_list *list_a, t_list *list_b, int dir, t_list **a)
{
	if (dir == A_TO_B)
	{
		a[kFrom] = list_a;
		a[kTo] = list_b;
	}
	else
	{
		a[kFrom] = list_b;
		a[kTo] = list_a;
	}
}

t_route		find_route_by_lowest_cost(t_list *list_a, t_list *list_b, int dir)
{
	t_list	*target[kTargetNum];
	t_route	*routes;
	t_route	ret;
	int		i;
	int		num;

	make_targets(list_a, list_b, dir, target);
	if (!(routes = malloc(target[kFrom]->length * sizeof(t_route))))
		raise_error("failed to allocate memory for find routes.");
	i = -1;
	while (++i < target[kFrom]->length)
	{
		num = list_get(target[kFrom], i);
		routes[i] = calculate_route(list_a, list_b, num, dir);
	}
	i = -1;
	while (++i < target[kFrom]->length)
		if (i == 0 || ret.total_cost > routes[i].total_cost)
			ret = routes[i];
	free(routes);
	return (ret);
}

t_bool		navigate(t_list *list_a, t_list *list_b, int dir)
{
	t_list	*target[kTargetNum];
	t_route	route;

	make_targets(list_a, list_b, dir, target);
	if (target[kFrom]->length == 0)
		return (FALSE);
	route = find_route_by_lowest_cost(list_a, list_b, dir);
	apply_distance_to_list(list_a, route.distance_a);
	apply_distance_to_list(list_b, route.distance_b);
	print_instructions_by_route(route);
	return (TRUE);
}
