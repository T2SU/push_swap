/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 06:23:49 by smun              #+#    #+#             */
/*   Updated: 2021/06/21 06:24:20 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	check_is_sorted(t_list *a, t_list *b, int init_element_count)
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
