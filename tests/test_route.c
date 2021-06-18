/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_route.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 03:30:19 by smun              #+#    #+#             */
/*   Updated: 2021/06/18 21:41:17 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include "testlib.h"
#include "common.h"
#include "push_swap.h"
#include <stdio.h>

static void init_test(t_list *list1, t_list *list2)
{
	list_init(list1, 0);
	list_push_one(list1, 5);
	list_push_one(list1, 9);
	list_push_one(list1, 3);
	list_push_one(list1, 7);
	// 7, 3, 9, 5
	
	list_init(list2, 0);
	list_push_one(list2, 1);
	list_push_one(list2, 2);
	list_push_one(list2, 4);
	list_push_one(list2, 6);
	list_push_one(list2, 8);
	list_push_one(list2, 10);
	// 10, 8, 6, 4, 2, 1
}

static void	test_calculate_route(void)
{
	t_list	list1;
	t_list	list2;

	init_test(&list1, &list2);
	t_route route = calculate_route(&list1, &list2, 7, A_TO_B);
	assert(route.distance_a == 0);
	assert(route.distance_b == 2);
	assert(route.total_cost == 2);

	route = calculate_route(&list1, &list2, 3, A_TO_B);
	assert(route.distance_a == 1);
	assert(route.distance_b == -2);
	assert(route.total_cost == 3);
	
	route = calculate_route(&list1, &list2, 9, A_TO_B);
	assert(route.distance_a == 2);
	assert(route.distance_b == 1);
	assert(route.total_cost == 2);
	
	route = calculate_route(&list1, &list2, 5, A_TO_B);
	assert(route.distance_a == -1);
	assert(route.distance_b == 3);
	assert(route.total_cost == 4);
}

static void	test_navigate_1(void)
{
	t_list	list1;
	t_list	list2;

	init_test(&list1, &list2);
	// A: 7 3 9 5
	// B: 10 8 6 4 2 1

	/* Step 1 - Nagivate */
	assert(navigate(&list1, &list2));
	// A: 7 3 9 5
	// B: 6 4 2 1 10 8
	assert(list_get(&list1, 0) == 7);
	assert(list_get(&list2, 0) == 6);
	
	/* Step 2 - Push */
	assert(list_push(&list1, &list2, A_TO_B));
	// A: 3 9 5
	// B: 7 6 4 2 1 10 8
	assert(list_get(&list1, 0) == 3);
	assert(list_get(&list2, 0) == 7);
	
	/* Step 3 - Nagivate */
	assert(navigate(&list1, &list2));
	// A: 9 5 3
	// B: 8 7 6 4 2 1 10
	assert(list_get(&list1, 0) == 9);
	assert(list_get(&list2, 0) == 8);
	
	/* Step 4 - Push */
	assert(list_push(&list1, &list2, A_TO_B));
	// A: 5 3
	// B: 9 8 7 6 4 2 1 10
	assert(list_get(&list1, 0) == 5);
	assert(list_get(&list2, 0) == 9);
	
	/* Step 5 - Nagivate */
	assert(navigate(&list1, &list2));
	// A: 5 3
	// B: 4 2 1 10 9 8 7 6
	assert(list_get(&list1, 0) == 5);
	assert(list_get(&list2, 0) == 4);
	
	/* Step 6 - Push */
	assert(list_push(&list1, &list2, A_TO_B));
	// A: 3
	// B: 5 4 2 1 10 9 8 7 6
	assert(list_get(&list1, 0) == 3);
	assert(list_get(&list2, 0) == 5);
	
	/* Step 7 - Nagivate */
	assert(navigate(&list1, &list2));
	// A: 3
	// B: 2 1 10 9 8 7 6 5 4
	assert(list_get(&list1, 0) == 3);
	assert(list_get(&list2, 0) == 2);
	
	/* Step 8 - Push */
	assert(list_push(&list1, &list2, A_TO_B));
	// A: 
	// B: 3 2 1 10 9 8 7 6 5 4
	assert(list1.length == 0);
	assert(list_get(&list2, 0) == 3);
}

static void	test_navigate_2(void)
{
	t_list	list1;
	t_list	list2;
	
	list_init(&list1, 0);
	list_init(&list2, 0);
	list_push_one(&list1, 6);
	list_push_one(&list2, 1);
	list_push_one(&list2, 2);
	list_push_one(&list2, 4);
	list_push_one(&list2, 5);
	list1.anchor = 1;
	list2.anchor = 5;
	navigate(&list1, &list2);
	list_push(&list1, &list2, A_TO_B);
	list_print(&list2);
}


int			main(int argc, char *argv[])
{
	do_test(&test_calculate_route);
	do_test_stdout(&test_navigate_1, "rrb\nrrb\npa\nrra\nrb\npa\nrrb\nrrb\nrrb\nrrb\npa\nrrb\nrrb\npa\n");
	do_test_stdout(&test_navigate_2, "rb\npa\n6 5 4 2 1 \n");
	print_test_result(argc, argv[0]);
	return 0;
}
