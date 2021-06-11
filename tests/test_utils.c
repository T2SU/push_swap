/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 15:09:34 by smun              #+#    #+#             */
/*   Updated: 2021/06/11 23:19:24 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <assert.h>
#include "testlib.h"
#include "common.h"

static void	test_distinct_true1(void)
{
	t_circularlist	list;

	circularlist_init(&list, 0);
	for (int i = 0; i < 100; i++)
		circularlist_push_one(&list, i);
	assert(is_all_distinct(&list) == TRUE);
}

static void	test_distinct_true2(void)
{
	t_circularlist	list;

	circularlist_init(&list, 0);
	for (int i = -50; i < 25; i++)
		circularlist_push_one(&list, i);
	assert(is_all_distinct(&list) == TRUE);
}

static void	test_distinct_false1(void)
{
	t_circularlist	list;

	circularlist_init(&list, 0);
	for (int i = 0; i <= 3; i++)
		circularlist_push_one(&list, 5);
	assert(is_all_distinct(&list) == FALSE);
}

static void	test_distinct_false2(void)
{
	t_circularlist	list;

	circularlist_init(&list, 0);
	circularlist_push_one(&list, 15);
	circularlist_push_one(&list, 25);
	circularlist_push_one(&list, 15);
	circularlist_push_one(&list, 35);
	circularlist_push_one(&list, 45);
	circularlist_push_one(&list, 15);
	assert(is_all_distinct(&list) == FALSE);
}

static void	test_distinct_false3(void)
{
	t_circularlist	list;

	circularlist_init(&list, 0);
	circularlist_push_one(&list, 15);
	circularlist_push_one(&list, 25);
	circularlist_push_one(&list, 5);
	circularlist_push_one(&list, 35);
	circularlist_push_one(&list, 45);
	circularlist_push_one(&list, 15);
	assert(is_all_distinct(&list) == FALSE);
}

static void test_atoi_strict(void)
{
	int value;
	assert(ft_atoi_strict("", &value) == FALSE);
	assert(ft_atoi_strict("--111", &value) == FALSE);
	assert(ft_atoi_strict("asdf", &value) == FALSE);
	assert(ft_atoi_strict("-asdf", &value) == FALSE);
	assert(ft_atoi_strict("14421a", &value) == FALSE);
	assert(ft_atoi_strict("-2147483649", &value) == FALSE);
	assert(ft_atoi_strict("2147483648", &value) == FALSE);
	assert(ft_atoi_strict("-1234567!", &value) == FALSE);
	assert(ft_atoi_strict(" ", &value) == FALSE);
	assert(ft_atoi_strict("-", &value) == FALSE);
	assert(ft_atoi_strict("     ", &value) == FALSE);
	assert(ft_atoi_strict("123456", &value) && value == 123456);
	assert(ft_atoi_strict("-123456", &value) && value == -123456);
	assert(ft_atoi_strict("0", &value) && value == 0);
	assert(ft_atoi_strict("000000", &value) && value == 0);
	assert(ft_atoi_strict("0000001", &value) && value == 1);
	assert(ft_atoi_strict("2147483647", &value) && value == 2147483647);
	assert(ft_atoi_strict("-2147483648", &value) && value == -2147483648);
	assert(ft_atoi_strict("15001234", &value) && value == 15001234);
	assert(ft_atoi_strict("-912928345", &value) && value == -912928345);
	assert(ft_atoi_strict("00000002147483647", &value) && value == 2147483647);
	assert(ft_atoi_strict("-00000000002147483648", &value) && value == -2147483648);
	assert(ft_atoi_strict("00000015001234", &value) && value == 15001234);
	assert(ft_atoi_strict("-000912928345", &value) && value == -912928345);
	assert(ft_atoi_strict("-000929283456", &value) && value == -929283456);
}

int			main(int argc, char *argv[])
{
	do_test(&test_distinct_true1);
	do_test(&test_distinct_true2);
	do_test(&test_distinct_false1);
	do_test(&test_distinct_false2);
	do_test(&test_distinct_false3);
	do_test(&test_atoi_strict);
	print_test_result(argc, argv[0]);
	return 0;
}
