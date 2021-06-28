/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 15:09:34 by smun              #+#    #+#             */
/*   Updated: 2021/06/28 13:51:14 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <assert.h>
#include "testlib.h"
#include "push_swap.h"

static void	test_parser_1(void)
{
	t_list	list;
	char	*argv_1[] = {"", "1", "5", "4", "2", "6"};

	list_init(&list, 0);
	parse_into_list(&list, 6, argv_1);
	assert(list_get(&list, 0) == 1);
	assert(list_get(&list, 1) == 5);
	assert(list_get(&list, 2) == 4);
	assert(list_get(&list, 3) == 2);
	assert(list_get(&list, 4) == 6);
	list_free(&list);
}

static void	test_parser_2(void)
{
	t_list	list;
	char	*argv_1[] = {"", "-1", "-5", "-4", "-2", "-6"};

	list_init(&list, 0);
	parse_into_list(&list, 6, argv_1);
	assert(list_get(&list, 0) == -1);
	assert(list_get(&list, 1) == -5);
	assert(list_get(&list, 2) == -4);
	assert(list_get(&list, 3) == -2);
	assert(list_get(&list, 4) == -6);
	list_free(&list);
}

static void	test_parser_3(void)
{
	t_list	list;
	char	*argv_1[] = {"", "-1 -5", "-4 -2", "-6"};

	list_init(&list, 0);
	parse_into_list(&list, 4, argv_1);
	assert(list_get(&list, 0) == -1);
	assert(list_get(&list, 1) == -5);
	assert(list_get(&list, 2) == -4);
	assert(list_get(&list, 3) == -2);
	assert(list_get(&list, 4) == -6);
	list_free(&list);
}

static void	test_parser_4(void)
{
	t_list	list;
	char	*argv_1[] = {"", "2147483647 21312 2222 55555 66 221 0 -1"};

	list_init(&list, 0);
	parse_into_list(&list, 2, argv_1);
	assert(list_get(&list, 0) == 2147483647);
	assert(list_get(&list, 1) == 21312);
	assert(list_get(&list, 2) == 2222);
	assert(list_get(&list, 3) == 55555);
	assert(list_get(&list, 4) == 66);
	assert(list_get(&list, 5) == 221);
	assert(list_get(&list, 6) == 0);
	assert(list_get(&list, 7) == -1);
	list_free(&list);
}

int			main(int argc, char *argv[])
{
	do_test(&test_parser_1);
	do_test(&test_parser_2);
	do_test(&test_parser_3);
	do_test(&test_parser_4);
	print_test_result(argc, argv[0]);
	return 0;
}
