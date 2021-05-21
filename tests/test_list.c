/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 14:30:08 by smun              #+#    #+#             */
/*   Updated: 2021/05/21 12:08:52 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include "testlib.h"
#include "common.h"

static void new_list(void)
{
	t_list	list;

	list_init(&list, 0);
	assert(list.capacity == 0);
	assert(list.length == 0);
}

static void push_one(void)
{
	t_list	list;

	list_init(&list, 0);
	assert(list_push_one(&list, 122));
	assert(list.capacity >= 1);
	assert(list.length == 1);
	assert(list.values[0] == 122);
	assert(list_push_one(&list, 256));
	assert(list.capacity >= 2);
	assert(list.length == 2);
	assert(list.values[0] == 256);
	assert(list.values[1] == 122);
	assert(list_push_one(&list, 354));
	assert(list.capacity >= 3);
	assert(list.length == 3);
	assert(list.values[0] == 354);
	assert(list.values[1] == 256);
	assert(list.values[2] == 122);
}

static void pop_one(void)
{
	t_list	list;

	list_init(&list, 0);
	list_push_one(&list, 1234);
	list_push_one(&list, 4567);
	list_push_one(&list, 101010);
	list_push_one(&list, 1256);
	assert(1256 == list_pop_one(&list));
	assert(101010 == list_pop_one(&list));
	assert(4567 == list_pop_one(&list));
	assert(1234 == list_pop_one(&list));
}

int main(int argc, char *argv[])
{
	do_test(&new_list);
	do_test(&push_one);
	do_test(&pop_one);
	print_test_result(argc, argv[0]);
	return 0;
}
