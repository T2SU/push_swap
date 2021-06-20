/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 06:16:56 by smun              #+#    #+#             */
/*   Updated: 2021/06/21 06:34:10 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <assert.h>
#include "testlib.h"
#include "checker.h"

static void test1(void)
{
	char *nums[] = {"", "214743647", "2", "1"};
	t_list a, b;
	
	list_init(&a, 3);
	list_init(&b, 0);
	parse_into_list(&a, 4, nums);
	do_action(&a, &b, parse_instruction("sa"));
	do_action(&a, &b, parse_instruction("rra"));
	check_is_sorted(&a, &b, 3);
	list_free(&a);
	list_free(&b);
}

int			main(int argc, char *argv[])
{
	do_test_stdout(&test1, "OK\n");
	print_test_result(argc, argv[0]);
	return 0;
}
