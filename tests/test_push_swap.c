/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 20:20:04 by smun              #+#    #+#             */
/*   Updated: 2021/06/18 23:51:47 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <assert.h>
#include "testlib.h"
#include "push_swap.h"

static void test_init(t_list *list_a, t_list *list_b)
{
	if (!list_init(list_a, 0))
		raise_error("failed to initialize the stack A");
	if (!list_init(list_b, 0))
		raise_error("failed to initialize the stack B");
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

	test_init(&list_a, &list_b);
	do_game(&list_a, &list_b, argc, argv);
	test_check_is_sorted(&list_a, &list_b);
	test_free(&list_a, &list_b);
}

static void test_case_2(void)
{
	const int	argc = 6;
	char		*argv[] = {"", "2", "3", "1", "7", "4"};
	t_list		list_a;
	t_list		list_b;

	test_init(&list_a, &list_b);
	do_game(&list_a, &list_b, argc, argv);
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
