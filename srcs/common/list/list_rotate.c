/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 01:55:34 by smun              #+#    #+#             */
/*   Updated: 2021/06/12 02:40:10 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void		list_rotate(t_list *list)
{
	list->anchor++;
}

void		list_reverse_rotate(t_list *list)
{
	list->anchor--;
}

void		list_rotate_order_by(t_list *list_a, t_list *list_b, int order)
{
	int		dest_a;
	int		dest_b;
	t_route	route;

	if (order == kDescending)
	{
		dest_a = list_a ? list_get_highest_number(list_a, INT_MAX) : 0;
		dest_b = list_b ? list_get_highest_number(list_b, INT_MAX) : 0;
	}
	else
	{
		dest_a = list_a ? list_get_lowest_number(list_a, INT_MIN) : 0;
		dest_b = list_b ? list_get_lowest_number(list_b, INT_MIN) : 0;
	}
	route.distance_a = list_a ? list_get_fastest_distance(list_a, dest_a) : 0;
	route.distance_b = list_b ? list_get_fastest_distance(list_b, dest_b) : 0;
	print_instructions_by_route(route);
	if (list_a != NULL)
		apply_distance_to_list(list_a, route.distance_a);
	if (list_b != NULL)
		apply_distance_to_list(list_b, route.distance_b);
}
