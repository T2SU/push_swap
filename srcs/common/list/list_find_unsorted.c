/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_find_unsorted.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 04:18:19 by smun              #+#    #+#             */
/*   Updated: 2021/06/21 09:46:23 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static int		search_unsorted_circular(t_list *list)
{
	int			num;

	num = list_get(list, list->length - 1);
	if (num > list_get(list, list->length))
		return (list->length - 1);
	return (-1);
}

static int		find_unsorted_biggest_index(t_list *list)
{
	int			i;
	int			num;
	int			biggest_index;
	int			biggest_num;

	i = 0;
	biggest_index = -1;
	biggest_num = INT_MIN;
	while (i < list->length - 1)
	{
		num = list_get(list, i);
		if (num > list_get(list, i + 1))
		{
			if (num > biggest_num)
			{
				biggest_index = i;
				biggest_num = num;
			}
		}
		i++;
	}
	if (biggest_index != -1)
		return (biggest_index);
	return (search_unsorted_circular(list));
}

t_bool			list_find_unsorted_biggest(t_list *list, int *pvalue)
{
	const int	unsorted_index = find_unsorted_biggest_index(list);
	int			num;

	if (unsorted_index == -1)
		return (FALSE);
	num = list_get(list, unsorted_index);
	*pvalue = list_get_fastest_distance(list, num);
	return (TRUE);
}
