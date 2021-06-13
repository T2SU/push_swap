/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   navigator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 01:50:31 by smun              #+#    #+#             */
/*   Updated: 2021/06/14 03:08:25 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

static t_route	find_route_by_lowest_cost(t_list *list_a, t_list *list_b)
{
	t_route		*routes;
	t_route		ret;
	int			i;

	if (!(routes = malloc(list_a->length * sizeof(t_route))))
		raise_error("failed to allocate memory for find routes.");
	i = -1;
	while (++i < list_a->length)
		routes[i] = calculate_route(list_a, list_b, list_get(list_a, i));
	i = -1;
	while (++i < list_a->length)
		if (i == 0 || ret.total_cost > routes[i].total_cost)
			ret = routes[i];
	free(routes);
	return (ret);
}

t_bool			navigate(t_list *list_a, t_list *list_b)
{
	t_route		route;
	
	if (list_a->length == 0)
		return (FALSE);
	route = find_route_by_lowest_cost(list_a, list_b);
	apply_distance_to_list(list_a, route.distance_a);
	apply_distance_to_list(list_b, route.distance_b);
	print_instructions_by_route(route);
	return (TRUE);
}
