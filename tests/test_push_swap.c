/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 20:20:04 by smun              #+#    #+#             */
/*   Updated: 2021/06/18 23:21:05 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <assert.h>
#include "testlib.h"
#include "push_swap.h"

static void test_init(t_list *list_a, t_list *list_b, int argc, char *argv[])
{
	if (!list_init(list_a, 0))
		raise_error("failed to initialize the stack A");
	if (!list_init(list_b, 0))
		raise_error("failed to initialize the stack B");
	parse_into_list(list_a, argc, argv);
	if (!is_all_distinct(list_a))
		raise_error("there are duplicates.");
}

static void test_free(t_list *list_a, t_list *list_b)
{
	list_free(list_a);
	list_free(list_b);
}

static void test_check_is_sorted(t_list *list_a, t_list *list_b)
{
	assert(list_b->length == 0);
	assert(list_get(list_a, 0) == list_get_lowest_number(list_a, INT_MIN));
	assert(list_get(list_a, -1) == list_get_highest_number(list_a, INT_MAX));
	assert(list_is_sorted(list_a, kAscending));
}

static void test_case_1(void)
{
	const int	argc = 6;
	char		*argv[] = {"", "1", "7", "5", "2", "4"};
	t_list		list_a;
	t_list		list_b;

	test_init(&list_a, &list_b, argc, argv);
	test_free(&list_a, &list_b);
}
//while (navigate(&list_a, &list_b))
//	list_push(&list_a, &list_b, A_TO_B);
//list_rotate_order_by_desc(&list_b);
//while (list_b.length > 0)
//	list_push(&list_a, &list_b, B_TO_A);

static void test_case_2(void)
{
	const int	argc = 6;
	char		*argv[] = {"", "2", "3", "1", "7", "4"};
	t_list		list_a;
	t_list		list_b;
	int			index;

	test_init(&list_a, &list_b, argc, argv);
	// 2 3 1 7 4
	// 정렬 안된 값: (3, 1), (7, 4), (4, 2)

	// 왼쪽이 가장 큰거: (7, 4)
	// 그러면 7을 B로 내림.

	// 2 3 1 4
	// 정렬 안된 값: (3, 1), (4, 2)
	
	// 왼쪽이 가장 큰 거: (4, 2)
	// 그러면 4를 B로 내림.

	// 2 3 1
	while (list_a.length > 3)
	{
		// 1. 정렬이 되어 있는가?
		if (!list_is_sorted(&list_a, kAscending))
		{
			// 1-1. 안되어 있다면 가장 큰 정렬 안된 요소를 B로 내리자.
			if (list_find_unsorted_biggest(&list_a, &index))
			{
				apply_distance_to_list(&list_a, index);
				list_push(&list_a, &list_b, A_TO_B);
				continue ;
			}
		}
		else
			break ;
	}
	// 2. B->A로 적절히 옮겨넣음
	while (list_b.length > 0)
	{
		t_route route = calculate_route(&list_a, &list_b, list_get(&list_b, 0), B_TO_A);
		print_instructions_by_route(route);
		apply_distance_to_list(&list_a, route.distance_a);
		apply_distance_to_list(&list_b, route.distance_b);
		list_push(&list_a, &list_b, B_TO_A);
	}
	list_rotate_order_by(&list_a, NULL, kAscending);
	test_check_is_sorted(&list_a, &list_b);
	test_free(&list_a, &list_b);
}

int			main(int argc, char *argv[])
{
	do_test_newline(&test_case_1, 12);
	do_test_newline(&test_case_2, 12);
	print_test_result(argc, argv[0]);
	return 0;
}
