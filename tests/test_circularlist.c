/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_circularlist.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 14:30:08 by smun              #+#    #+#             */
/*   Updated: 2021/06/12 02:31:44 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include "testlib.h"
#include "common.h"

static void new_list(void)
{
	t_circularlist	list;

	circularlist_init(&list, 0);
	assert(list.capacity == 0);
	assert(list.length == 0);
	circularlist_free(&list);

	circularlist_init(&list, 5);
	assert(list.capacity == 5);
	assert(list.length == 0);
	circularlist_free(&list);

	circularlist_init(&list, -5);
	assert(list.capacity == 0);
	assert(list.length == 0);
	circularlist_free(&list);

	circularlist_init(&list, -2147483648);
	assert(list.capacity == 0);
	assert(list.length == 0);
	circularlist_free(&list);
}

static void push_one(void)
{
	t_circularlist	list;

	circularlist_init(&list, 0);
	assert(circularlist_push_one(&list, 122));
	assert(list.capacity >= 1);
	assert(list.length == 1);
	assert(list.values[0] == 122);
	assert(circularlist_push_one(&list, 256));
	assert(list.capacity >= 2);
	assert(list.length == 2);
	assert(list.values[0] == 256);
	assert(list.values[1] == 122);
	assert(circularlist_push_one(&list, 354));
	assert(list.capacity >= 3);
	assert(list.length == 3);
	assert(list.values[0] == 354);
	assert(list.values[1] == 256);
	assert(list.values[2] == 122);
	circularlist_free(&list);

}

static void pop_one(void)
{
	t_circularlist	list;

	circularlist_init(&list, 0);
	circularlist_push_one(&list, 1234);
	circularlist_push_one(&list, 4567);
	circularlist_push_one(&list, 101010);
	circularlist_push_one(&list, 1256);
	assert(1256 == circularlist_pop_one(&list));
	assert(101010 == circularlist_pop_one(&list));
	assert(4567 == circularlist_pop_one(&list));
	assert(1234 == circularlist_pop_one(&list));
	circularlist_free(&list);
}

static void rotate(void)
{
	t_circularlist	list;

	circularlist_init(&list, 0);
	circularlist_push_one(&list, 1234);
	circularlist_push_one(&list, 4567);
	circularlist_push_one(&list, 101010);
	circularlist_push_one(&list, 1256);
	// 1256 101010 4567 1234
	circularlist_rotate(&list);
	// 101010 4567 1234 1256
	assert(101010 == circularlist_get(&list, 0));
	circularlist_rotate(&list);
	// 4567 1234 1256 101010
	circularlist_rotate(&list);
	// 1234 1256 101010 4567
	assert(1234 == circularlist_get(&list, 0));
	// 1256 101010 4567
	assert(1234 == circularlist_pop_one(&list));
	assert(1256 == circularlist_get(&list, 0));
	assert(4567 == circularlist_get(&list, -1));
	circularlist_rotate(&list);
	// 101010 4567 1256
	assert(101010 == circularlist_get(&list, 0));
	assert(101010 == circularlist_get(&list, -3));
	assert(101010 == circularlist_get(&list, -6));
	assert(101010 == circularlist_get(&list, -9));
	assert(101010 == circularlist_get(&list, 3));
	assert(101010 == circularlist_get(&list, 6));
	assert(101010 == circularlist_get(&list, 9));
	circularlist_free(&list);
}

static void rotate_reverse(void)
{
	t_circularlist	list;

	circularlist_init(&list, 0);
	circularlist_push_one(&list, 1234);
	circularlist_push_one(&list, 4567);
	circularlist_push_one(&list, 101010);
	circularlist_push_one(&list, 1256);
	// 1256 101010 4567 1234
	circularlist_reverse_rotate(&list);
	// 1234 1256 101010 4567
	assert(1234 == circularlist_get(&list, 0));
	assert(1234 == circularlist_get(&list, 4));
	assert(1234 == circularlist_get(&list, -4));
	circularlist_reverse_rotate(&list);
	// 4567 1234 1256 101010
	assert(4567 == circularlist_get(&list, 0));
	assert(4567 == circularlist_get(&list, 4));
	assert(4567 == circularlist_get(&list, -4));
	circularlist_reverse_rotate(&list);
	// 101010 4567 1234 1256
	assert(4567 == circularlist_get(&list, 1));
	assert(1256 == circularlist_get(&list, -1));
	assert(101010 == circularlist_pop_one(&list));
	// 4567 1234 1256
	assert(4567 == circularlist_pop_one(&list));
	// 1234 1256
	assert(1234 == circularlist_pop_one(&list));
	// 1256
	assert(1256 == circularlist_pop_one(&list));
	assert(0 == list.length);
}

static void push_rotate_pop(void)
{
	t_circularlist	list;

	circularlist_init(&list, 0);
	circularlist_push_one(&list, 1234);
	circularlist_push_one(&list, 4567);
	// 4567 1234
	assert(circularlist_get(&list, 0) == 4567);
	circularlist_reverse_rotate(&list);
	// 1234 4567
	assert(circularlist_get(&list, 0) == 1234);
	circularlist_reverse_rotate(&list);
	// 4567 1234
	assert(circularlist_get(&list, 0) == 4567);
	circularlist_push_one(&list, 133221);
	// 133221 4567 1234
	assert(circularlist_get(&list, 0) == 133221);
	circularlist_rotate(&list);
	// 4567 1234 133221
	assert(circularlist_get(&list, 0) == 4567);
	circularlist_push_one(&list, 333123);
	// 333123 4567 1234 133221
	assert(circularlist_get(&list, -1) == 133221);
	circularlist_reverse_rotate(&list);
	// 133221 333123 4567 1234
	assert(circularlist_get(&list, 1) == 333123);
	assert(circularlist_pop_one(&list) == 133221);
	// 333123 4567 1234
	assert(circularlist_pop_one(&list) == 333123);
	// 4567 1234
	assert(circularlist_pop_one(&list) == 4567);
	// 1234
	circularlist_push_one(&list, 5120);
	// 5120 1234
	assert(circularlist_get(&list, -3) == 1234);
	circularlist_reverse_rotate(&list);
	// 1234 5120
	circularlist_push_one(&list, 666);
	// 666 1234 5120
	assert(circularlist_get(&list, 1) == 1234);
	assert(circularlist_pop_one(&list) == 666);
	assert(circularlist_pop_one(&list) == 1234);
	assert(circularlist_pop_one(&list) == 5120);
	assert(list.length == 0);
}

static void clone(void)
{
	t_circularlist	li1;
	t_circularlist	li2;

	circularlist_init(&li1, 0);
	circularlist_init(&li2, 5);
	for (int i = 0; i < 100; i++)
		circularlist_push_one(&li1, i);
	for (int i = 0; i < 5; i++)
		circularlist_push_one(&li2, -5);
	assert(circularlist_clone(&li1, &li2));
	for (int i = 0; i < 5; i++)
		assert(li2.values[i] != -5);
	for (int i = 0; i < 10; i++)
		circularlist_reverse_rotate(&li1);
	for (int i = 99; i >= 0; i--)
	{
		int a = circularlist_pop_one(&li1);
		int b = (i + 10) % 100;
		assert(a == b);
	}
	for (int i = 99; i >= 0; i--)
	{
		int a = circularlist_pop_one(&li2);
		int b = i;
		assert(a == b);
	}
}

int main(int argc, char *argv[])
{
	do_test(&new_list);
	do_test(&push_one);
	do_test(&pop_one);
	do_test(&rotate);
	do_test(&rotate_reverse);
	do_test(&push_rotate_pop);
	do_test(&clone);
	print_test_result(argc, argv[0]);
	return 0;
}
