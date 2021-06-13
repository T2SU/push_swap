/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 20:20:04 by smun              #+#    #+#             */
/*   Updated: 2021/06/14 02:15:59 by smun             ###   ########.fr       */
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

static void test_case_1(void)
{
	const int	argc = 6;
	char		*argv[] = {"", "1", "7", "5", "2", "4", "6"};
	t_list		list_a;
	t_list		list_b;

	test_init(&list_a, &list_b, argc, argv);
	while (navigate(&list_a, &list_b))
		list_push(&list_a, &list_b, A_TO_B);
	list_print(&list_b);
	test_free(&list_a, &list_b);
}

int			main(int argc, char *argv[])
{
	do_test(&test_case_1);
	print_test_result(argc, argv[0]);
	return 0;
}
