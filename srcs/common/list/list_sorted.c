/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_sorted.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 03:41:56 by smun              #+#    #+#             */
/*   Updated: 2021/06/19 01:47:03 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static int	get_anchor(t_list *list, int order)
{
	int		destination;
	
	if (order == kDescending)
		destination = list_get_highest_number(list, INT_MAX);
	else
		destination = list_get_lowest_number(list, INT_MIN);
	return (list_get_fastest_distance(list, destination));
}

t_bool		list_is_sorted(t_list *list, int order)
{
	int		i;
	int		anchor;
	int		num;
	int		last;

	anchor = get_anchor(list, order);
	i = 0;
	while (i < list->length)
	{
		num = list_get(list, i + anchor);
		if (i > 0)
		{
			if (order == kAscending && num < last)
				return (FALSE);
			if (order == kDescending && num > last)
				return (FALSE);
		}
		last = num;
		i++;
	}
	return (TRUE);
}
