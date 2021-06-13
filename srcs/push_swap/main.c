/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 20:35:41 by smun              #+#    #+#             */
/*   Updated: 2021/06/13 19:32:11 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		parse_into_list(t_list *list, int argc, char *argv[])
{
	const int	start_index = 1;
	int			i;
	int			num;

	i = start_index;
	if (argc <= start_index)
		raise_error("lacked arguments.");
	while (i < argc)
	{
		if (!ft_atoi_strict(argv[i], &num))
			raise_error_description("unparsable into integer.", argv[i]);
		list_push_one(list, num);
		i++;
	}
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
	while (navigate(&list_a, &list_b))
		list_push(&list_a, &list_b, A_TO_B);
	while (list_b.length > 0)
		list_push(&list_a, &list_b, B_TO_A);
	list_free(&list_a);
	list_free(&list_b);
	return (0);
}
