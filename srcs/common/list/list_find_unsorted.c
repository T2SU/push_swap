/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_find_unsorted.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 04:18:19 by smun              #+#    #+#             */
/*   Updated: 2021/06/19 01:40:53 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static t_bool	search_unsorted_circular(t_list *list, int *pvalue)
{
	int			num;

	num = list_get(list, list->length - 1);
	if (num > list_get(list, list->length))
	{
		*pvalue = list->length - 1;
		return (TRUE);
	}
	return (FALSE);
}

t_bool			list_find_unsorted_biggest(t_list *list, int *pvalue)
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
	if ((*pvalue = biggest_index) != -1)
		return (TRUE);
	return (search_unsorted_circular(list, pvalue));
}
