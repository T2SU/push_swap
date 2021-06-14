/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 20:35:41 by smun              #+#    #+#             */
/*   Updated: 2021/06/14 18:15:59 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		case_tiny(t_list *list_a, t_list *list_b)
{
	
}

static void		case_huge(t_list *list_a, t_list *list_b)
{
	while (navigate(&list_a, &list_b))
		list_push(&list_a, &list_b, A_TO_B);
	list_rotate_order_by_desc(&list_b);
	while (list_b->length > 0)
		list_push(&list_a, &list_b, B_TO_A);
}

int				main(int argc, char *argv[])
{
	t_list		list_a;
	t_list		list_b;

	if (!list_init(&list_a, 0))
		raise_error("failed to initialize the stack A");
	if (!list_init(&list_b, 0))
		raise_error("failed to initialize the stack B");
	parse_into_list(&list_a, argc, argv);
	if (!is_all_distinct(&list_a))
		raise_error("there are duplicates.");
	if (argc - 1 > 10)
		case_huge(&list_a, &list_b);
	else
		case_tiny(&list_a, &list_b);
	list_free(&list_a);
	list_free(&list_b);
	return (0);
}
