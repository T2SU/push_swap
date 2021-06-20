/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 20:35:41 by smun              #+#    #+#             */
/*   Updated: 2021/06/21 06:24:14 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <unistd.h>

int				main(int argc, char *argv[])
{
	t_list		list_a;
	t_list		list_b;
	int			elem_count;

	if (argc <= 1)
		return (0);
	if (!list_init(&list_a, 0))
		raise_error("failed to initialize the stack A");
	if (!list_init(&list_b, 0))
		raise_error("failed to initialize the stack B");
	parse_into_list(&list_a, argc, argv);
	if (!is_all_distinct(&list_a))
		raise_error("there are duplicates.");
	elem_count = list_a.length + list_b.length;
	while (action_from_stdin(&list_a, &list_b)) ;
	check_is_sorted(&list_a, &list_b, elem_count);
	list_free(&list_a);
	list_free(&list_b);
	return (0);
}
