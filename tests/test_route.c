/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_route.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 03:30:19 by smun              #+#    #+#             */
/*   Updated: 2021/06/12 21:52:19 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include "testlib.h"
#include "common.h"
#include <stdio.h>

static void	test_calculate_route(void)
{
	t_list	list1;
	t_list	list2;

	list_init(&list1, 0);
	list_push_one(&list1, 5);
	list_push_one(&list1, 9);
	list_push_one(&list1, 3);
	list_push_one(&list1, 7);
	// 7, 3, 9, 5
	
	list_init(&list2, 0);
	list_push_one(&list2, 1);
	list_push_one(&list2, 2);
	list_push_one(&list2, 4);
	list_push_one(&list2, 6);
	list_push_one(&list2, 8);
	list_push_one(&list2, 10);
	// 10, 8, 6, 4, 2, 1

	t_route route = calculate_route(&list1, &list2, 7);
	assert(route.distance_a == 0);
	assert(route.distance_b == 2);
	assert(route.total_cost == 2);

	route = calculate_route(&list1, &list2, 3);
	assert(route.distance_a == 1);
	assert(route.distance_b == -2);
	assert(route.total_cost == 3);
	
	route = calculate_route(&list1, &list2, 9);
	assert(route.distance_a == 2);
	assert(route.distance_b == 1);
	assert(route.total_cost == 2);
	
	route = calculate_route(&list1, &list2, 5);
	assert(route.distance_a == -1);
	assert(route.distance_b == 3);
	assert(route.total_cost == 4);
}

int			main(int argc, char *argv[])
{
	do_test(&test_calculate_route);
	print_test_result(argc, argv[0]);
	return 0;
}
