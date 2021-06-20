/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 14:30:08 by smun              #+#    #+#             */
/*   Updated: 2021/06/21 06:33:27 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include "testlib.h"
#include "common.h"

static void new_list(void)
{
	t_list	list;

	list_init(&list, 0);
	assert(list.capacity == 0);
	assert(list.length == 0);
	list_free(&list);

	list_init(&list, 5);
	assert(list.capacity == 5);
	assert(list.length == 0);
	list_free(&list);

	list_init(&list, -5);
	assert(list.capacity == 0);
	assert(list.length == 0);
	list_free(&list);

	list_init(&list, -2147483648);
	assert(list.capacity == 0);
	assert(list.length == 0);
	list_free(&list);
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
	list_free(&list);

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
	list_free(&list);
}

static void rotate(void)
{
	t_list	list;

	list_init(&list, 0);
	list_push_one(&list, 1234);
	list_push_one(&list, 4567);
	list_push_one(&list, 101010);
	list_push_one(&list, 1256);
	// 1256 101010 4567 1234
	list_rotate(&list);
	// 101010 4567 1234 1256
	assert(101010 == list_get(&list, 0));
	list_rotate(&list);
	// 4567 1234 1256 101010
	list_rotate(&list);
	// 1234 1256 101010 4567
	assert(1234 == list_get(&list, 0));
	// 1256 101010 4567
	assert(1234 == list_pop_one(&list));
	assert(1256 == list_get(&list, 0));
	assert(4567 == list_get(&list, -1));
	list_rotate(&list);
	// 101010 4567 1256
	assert(101010 == list_get(&list, 0));
	assert(101010 == list_get(&list, -3));
	assert(101010 == list_get(&list, -6));
	assert(101010 == list_get(&list, -9));
	assert(101010 == list_get(&list, 3));
	assert(101010 == list_get(&list, 6));
	assert(101010 == list_get(&list, 9));
	list_free(&list);
}

static void rotate_reverse(void)
{
	t_list	list;

	list_init(&list, 0);
	list_push_one(&list, 1234);
	list_push_one(&list, 4567);
	list_push_one(&list, 101010);
	list_push_one(&list, 1256);
	// 1256 101010 4567 1234
	list_reverse_rotate(&list);
	// 1234 1256 101010 4567
	assert(1234 == list_get(&list, 0));
	assert(1234 == list_get(&list, 4));
	assert(1234 == list_get(&list, -4));
	list_reverse_rotate(&list);
	// 4567 1234 1256 101010
	assert(4567 == list_get(&list, 0));
	assert(4567 == list_get(&list, 4));
	assert(4567 == list_get(&list, -4));
	list_reverse_rotate(&list);
	// 101010 4567 1234 1256
	assert(4567 == list_get(&list, 1));
	assert(1256 == list_get(&list, -1));
	assert(101010 == list_pop_one(&list));
	// 4567 1234 1256
	assert(4567 == list_pop_one(&list));
	// 1234 1256
	assert(1234 == list_pop_one(&list));
	// 1256
	assert(1256 == list_pop_one(&list));
	assert(0 == list.length);
}

static void push_rotate_pop(void)
{
	t_list	list;

	list_init(&list, 0);
	list_push_one(&list, 1234);
	list_push_one(&list, 4567);
	// 4567 1234
	assert(list_get(&list, 0) == 4567);
	list_reverse_rotate(&list);
	// 1234 4567
	assert(list_get(&list, 0) == 1234);
	list_reverse_rotate(&list);
	// 4567 1234
	assert(list_get(&list, 0) == 4567);
	list_push_one(&list, 133221);
	// 133221 4567 1234
	assert(list_get(&list, 0) == 133221);
	list_rotate(&list);
	// 4567 1234 133221
	assert(list_get(&list, 0) == 4567);
	list_push_one(&list, 333123);
	// 333123 4567 1234 133221
	assert(list_get(&list, -1) == 133221);
	list_reverse_rotate(&list);
	// 133221 333123 4567 1234
	assert(list_get(&list, 1) == 333123);
	assert(list_pop_one(&list) == 133221);
	// 333123 4567 1234
	assert(list_pop_one(&list) == 333123);
	// 4567 1234
	assert(list_pop_one(&list) == 4567);
	// 1234
	list_push_one(&list, 5120);
	// 5120 1234
	assert(list_get(&list, -3) == 1234);
	list_reverse_rotate(&list);
	// 1234 5120
	list_push_one(&list, 666);
	// 666 1234 5120
	assert(list_get(&list, 1) == 1234);
	assert(list_pop_one(&list) == 666);
	assert(list_pop_one(&list) == 1234);
	assert(list_pop_one(&list) == 5120);
	assert(list.length == 0);
}

static void clone(void)
{
	t_list	li1;
	t_list	li2;

	list_init(&li1, 0);
	list_init(&li2, 5);
	for (int i = 0; i < 100; i++)
		list_push_one(&li1, i);
	for (int i = 0; i < 5; i++)
		list_push_one(&li2, -5);
	assert(list_clone(&li1, &li2));
	for (int i = 0; i < 5; i++)
		assert(list_get(&li2, i) != -5);
	for (int i = 0; i < 10; i++)
		list_reverse_rotate(&li1);
	for (int i = 99; i >= 0; i--)
	{
		int a = list_pop_one(&li1);
		int b = (i + 10) % 100;
		assert(a == b);
	}
	for (int i = 99; i >= 0; i--)
	{
		int a = list_pop_one(&li2);
		int b = i;
		assert(a == b);
	}
}

static void is_sorted(void)
{
	t_list	li1;

	list_init(&li1, 0);
	list_push_one(&li1, 6);
	list_push_one(&li1, 1);
	list_push_one(&li1, 2);
	list_push_one(&li1, 3);
	list_push_one(&li1, 4);
	// 4 3 2 1 6
	for (int i = 0; i < 100; i++)
	{
		assert(list_is_sorted(&li1, kDescending));
		assert(!list_is_sorted(&li1, kAscending));
		list_rotate(&li1);
	}
	list_free(&li1);
	list_init(&li1, 0);
	list_push_one(&li1, 0);
	list_push_one(&li1, 4);
	list_push_one(&li1, 3);
	list_push_one(&li1, 2);
	list_push_one(&li1, 1);
	// 1 2 3 4 0
	for (int i = 0; i < 100; i++)
	{
		assert(!list_is_sorted(&li1, kDescending));
		assert(list_is_sorted(&li1, kAscending));
		list_reverse_rotate(&li1);
	}
}

static void test_swap(void)
{
	t_list	li1;

	list_init(&li1, 0);
	assert(list_swap(&li1, "aa") == FALSE);
	list_push_one(&li1, 1234);
	assert(list_swap(&li1, NULL) == FALSE);
	list_push_one(&li1, 5678);
	assert(list_get(&li1, 0) == 5678);
	assert(list_get(&li1, 1) == 1234);
	assert(list_swap(&li1, "b"));
	assert(list_get(&li1, 0) == 1234);
	assert(list_get(&li1, 1) == 5678);
	assert(list_swap(&li1, ""));
	assert(list_get(&li1, 0) == 5678);
	assert(list_get(&li1, 1) == 1234);
	list_push_one(&li1, 9012);
	assert(list_swap(&li1, "Hello Hello"));
	assert(list_get(&li1, 0) == 5678);
	assert(list_get(&li1, 1) == 9012);
	list_free(&li1);
}

static void test_list_anchor(void)
{
	t_list	li1;
	t_list	li2;

	list_init(&li1, 5);
	li1.values[0] = 1;
	li1.values[1] = 2;
	li1.values[2] = 4;
	li1.length = 3;
	li1.anchor = 6;
	list_init(&li2, 2);
	li2.values[0] = 5;
	li2.values[1] = 7;
	li2.length = 2;
	li2.anchor = 2;
	assert(list_get(&li1, 0) == 1);
	list_push_and_print(&li1, &li2, B_TO_A);
	assert(list_get(&li1, 0) == 5);
	for (int i = 0; i < 1234; i++)
		list_reverse_rotate(&li1);
	assert(list_get(&li1, 0) == 2);
	list_push_and_print(&li1, &li2, B_TO_A);
	assert(list_get(&li1, 0) == 7);
	list_free(&li1);
	list_free(&li2);
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
	do_test(&is_sorted);
	do_test_stdout(&test_swap, "b\n\nHello Hello\n");
	do_test_stdout(&test_list_anchor, "pa\npa\n");
	print_test_result(argc, argv[0]);
	return 0;
}
