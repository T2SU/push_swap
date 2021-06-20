/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 20:35:41 by smun              #+#    #+#             */
/*   Updated: 2021/06/21 05:58:56 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <unistd.h>

static void		check_is_sorted(t_list *a, t_list *b, int init_element_count)
{
	if (a->length != init_element_count || b->length != 0)
		print("KO\n");
	else if (!list_is_sorted(a, kAscending))
		print("KO\n");
	else if (list_get(a, 0) != list_get_lowest_number(a, INT_MIN))
		print("KO\n");
	else if (list_get(a, -1) != list_get_highest_number(a, INT_MAX))
		print("KO\n");
	else
		print("OK\n");
}

int				main(int argc, char *argv[])
{
	t_list		list_a;
	t_list		list_b;

	if (argc <= 1)
		return (0);
	if (!list_init(&list_a, 0))
		raise_error("failed to initialize the stack A");
	if (!list_init(&list_b, 0))
		raise_error("failed to initialize the stack B");
	parse_into_list(&list_a, argc, argv);
	if (!is_all_distinct(&list_a))
		raise_error("there are duplicates.");
	while (action_from_stdin(&list_a, &list_b)) ;
	check_is_sorted(&list_a, &list_b, argc - 1);
	list_free(&list_a);
	list_free(&list_b);
	return (0);
}
