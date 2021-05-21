/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 15:09:34 by smun              #+#    #+#             */
/*   Updated: 2021/05/21 15:32:33 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include "testlib.h"
#include "common.h"

static void	test_distinct_true1(void)
{
	t_list	list;

	list_init(&list, 0);
	for (int i = 0; i < 100; i++)
		list_push_one(&list, i);
	assert(is_all_distinct(&list) == TRUE);
}

static void	test_distinct_true2(void)
{
	t_list	list;

	list_init(&list, 0);
	for (int i = -50; i < 25; i++)
		list_push_one(&list, i);
	assert(is_all_distinct(&list) == TRUE);
}

static void	test_distinct_false1(void)
{
	t_list	list;

	list_init(&list, 0);
	for (int i = 0; i <= 3; i++)
		list_push_one(&list, 5);
	assert(is_all_distinct(&list) == FALSE);
}

static void	test_distinct_false2(void)
{
	t_list	list;

	list_init(&list, 0);
	list_push_one(&list, 15);
	list_push_one(&list, 25);
	list_push_one(&list, 15);
	list_push_one(&list, 35);
	list_push_one(&list, 45);
	list_push_one(&list, 15);
	assert(is_all_distinct(&list) == FALSE);
}

static void	test_distinct_false3(void)
{
	t_list	list;

	list_init(&list, 0);
	list_push_one(&list, 15);
	list_push_one(&list, 25);
	list_push_one(&list, 5);
	list_push_one(&list, 35);
	list_push_one(&list, 45);
	list_push_one(&list, 15);
	assert(is_all_distinct(&list) == FALSE);
}

static void test_atoi_b(void)
{

}

int			main(int argc, char *argv[])
{
	do_test(&test_distinct_true1);
	do_test(&test_distinct_true2);
	do_test(&test_distinct_false1);
	do_test(&test_distinct_false2);
	do_test(&test_distinct_false3);
	print_test_result(argc, argv[0]);
	return 0;
}
