/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 20:20:04 by smun              #+#    #+#             */
/*   Updated: 2021/06/15 00:35:43 by smun             ###   ########.fr       */
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
	char		*argv[] = {"", "1", "7", "5", "2", "4"};
	t_list		list_a;
	t_list		list_b;

	test_init(&list_a, &list_b, argc, argv);
	while (navigate(&list_a, &list_b))
		list_push(&list_a, &list_b, A_TO_B);
	list_rotate_order_by_desc(&list_b);
	while (list_b.length > 0)
		list_push(&list_a, &list_b, B_TO_A);
	test_free(&list_a, &list_b);
}

int			main(int argc, char *argv[])
{
	do_test_newline(&test_case_1, 12);
	print_test_result(argc, argv[0]);
	return 0;
}
