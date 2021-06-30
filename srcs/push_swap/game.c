/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 23:47:15 by smun              #+#    #+#             */
/*   Updated: 2021/06/30 10:22:17 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Sort cases in little elements.
**  1. Send unsorted numbers to Stack B order by descending.
**  2. Repeat until remaining elements at least 3, in Stack A.
**  3. If Stack A is unsorted, do swap action.
**  4. Send Stack B Numbers to Stack A to proper index.
*/

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
		}
	}
	if (!list_is_sorted(list_a, kAscending))
		list_swap(list_a, "sa");
	while (navigate(list_a, list_b, B_TO_A))
		list_push_and_print(list_a, list_b, B_TO_A);
	list_rotate_order_by(list_a, NULL, kAscending);
}

/*
** Sort cases in large elements.
** Applicates of A* algorithm, the solution to find fastest route.
** Search each times for the best solution for sorting Stack B by
** 'pb' as descending.
*/

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
	while (navigate(a, b, A_TO_B))
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
	if (list_a->length > 5)
		case_huge(list_a, list_b);
	else
		case_tiny(list_a, list_b);
}
