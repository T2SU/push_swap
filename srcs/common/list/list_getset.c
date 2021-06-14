/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_getset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 01:57:30 by smun              #+#    #+#             */
/*   Updated: 2021/06/14 03:44:22 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int			list_get_real_index(t_list *list, int index)
{
	int		trimmed;

	trimmed = index;
	if (list->length > 0)
		trimmed %= list->length;
	if (trimmed < 0)
		trimmed += list->length;
	return (trimmed);
}

int			list_get(t_list *list, int index)
{
	int		real_idx;

	real_idx = list_get_real_index(list, index + list->anchor);
	return (list->values[real_idx]);
}

void		list_set(t_list *list, int index, int value)
{
	int		real_idx;

	real_idx = list_get_real_index(list, index + list->anchor);
	list->values[real_idx] = value;
}

int			list_get_highest_number(t_list *list, int basis)
{
	int		highest;
	int		i;
	int		num;

	highest = INT_MIN;
	i = 0;
	while (i < list->length)
	{
		num = list_get(list, i++);
		if (basis < num)
			continue;
		if (highest < num)
			highest = num;
	}
	return (highest);
}

int			list_get_lowest_number(t_list *list, int basis)
{
	int		lowest;
	int		i;
	int		num;

	lowest = INT_MAX;
	i = 0;
	while (i < list->length)
	{
		num = list_get(list, i++);
		if (basis > num)
			continue;
		if (lowest > num)
			lowest = num;
	}
	return (lowest);
}
