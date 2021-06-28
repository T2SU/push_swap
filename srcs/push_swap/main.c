/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 20:35:41 by smun              #+#    #+#             */
/*   Updated: 2021/06/28 15:15:53 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			main(int argc, char *argv[])
{
	t_list	list_a;
	t_list	list_b;

	if (argc <= 1)
		return (0);
	if (!list_init(&list_a, 0))
		raise_error("failed to initialize the stack A");
	if (!list_init(&list_b, 0))
		raise_error("failed to initialize the stack B");
	do_game(&list_a, &list_b, argc, argv);
	list_free(&list_a);
	list_free(&list_b);
	return (0);
}
