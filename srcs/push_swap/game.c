/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 23:47:15 by smun              #+#    #+#             */
/*   Updated: 2021/06/21 08:46:53 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	case_tiny(t_list *list_a, t_list *list_b)
{
	t_route	route;

	ft_bzero(&route, sizeof(t_route));
	while (list_a->length > 3 && !list_is_sorted(list_a, kAscending))
	{
		if (list_find_unsorted_biggest(list_a, &route.distance_a))
		{
			print_instructions_by_route(route);
			apply_distance_to_list(list_a, route.distance_a);
			list_push_and_print(list_a, list_b, A_TO_B);
			continue ;
		}
	}
	if (!list_is_sorted(list_a, kAscending))
		list_swap(list_a, "sa");
	while (list_b->length > 0)
	{
		route = calculate_route(list_a, list_b, list_get(list_b, 0), B_TO_A);
		print_instructions_by_route(route);
		apply_distance_to_list(list_a, route.distance_a);
		apply_distance_to_list(list_b, route.distance_b);
		list_push_and_print(list_a, list_b, B_TO_A);
	}
	list_rotate_order_by(list_a, NULL, kAscending);
}

static void	case_huge(t_list *a, t_list *b)
{
	if (list_is_sorted(a, kAscending))
	{
		if (list_get(a, -1) == list_get_highest_number(a, INT_MAX))
			if (list_get(a, 0) == list_get_lowest_number(a, INT_MIN))
				return ;
		list_rotate_order_by(a, NULL, kAscending);
		return ;
	}
	while (navigate(a, b))
		list_push_and_print(a, b, A_TO_B);
	list_rotate_order_by(NULL, b, kDescending);
	while (b->length > 0)
		list_push_and_print(a, b, B_TO_A);
}

void		do_game(t_list *list_a, t_list *list_b, int argc, char *argv[])
{
	parse_into_list(list_a, argc, argv);
	if (!is_all_distinct(list_a))
		raise_error("there are duplicates.");
	if (argc - 1 > 5)
		case_huge(list_a, list_b);
	else
		case_tiny(list_a, list_b);
}
