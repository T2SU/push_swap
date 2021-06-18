/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_find_unsorted.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 04:18:19 by smun              #+#    #+#             */
/*   Updated: 2021/06/18 22:30:28 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

t_bool		list_find_unsorted_biggest(t_list *list, int *pvalue)
{
	int		i;
	int		num;
	int		biggest_index;
	int		biggest_num;

	i = 0;
	biggest_index = -1;
	biggest_num = INT_MIN;
	while (i < list->length)
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
	return ((*pvalue = biggest_index) != -1);
}
