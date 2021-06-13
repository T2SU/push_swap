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

void	list_rotate(t_list *list)
{
	list->anchor++;
}

void	list_reverse_rotate(t_list *list)
{
	list->anchor--;
}

void		list_rotate_order_by_desc(t_list *list)
{
	int		max;
	t_route	route;

	max = list_get_highest_number(list, INT_MAX);
	route.distance_a = 0;
	route.distance_b = list_get_fastest_distance(list, max);
	print_instructions_by_route(route);
	apply_distance_to_list(list, route.distance_b);
}
