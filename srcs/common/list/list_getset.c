/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_getset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 01:57:30 by smun              #+#    #+#             */
/*   Updated: 2021/06/21 09:46:04 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

/*
**  Anchor helps to implement circular lists with ease.
**   Eg, We have a list like this:
**
**                     (Anchor = 0)
**            +---+---+---+---+---+---+---+
** Buffer:    | 2 | 1 | 3 | 5 | 7 | 9 | 0 |
**            +---+---+---+---+---+---+---+
** RealIndex:   0   1   2   3   4   5   6
** ListIndex:  -7  -6  -5  -4  -3  -2  -1
**              0   1   2   3   4   5   6
**              7   8   9  10  11  12  13
**  (* ListIndex is the index used to get a value from a list.)
**
** If we rotate this list once, anchor value will increase once.
**
**                     (Anchor = 1)
**            +---+---+---+---+---+---+---+
** Buffer:    | 2 | 1 | 3 | 5 | 7 | 9 | 0 |
**            +---+---+---+---+---+---+---+
** RealIndex:   0   1   2   3   4   5   6
** ListIndex:  -6  -5  -4  -3  -2  -1   0
**              1   2   3   4   5   6   7
**              8   9  10  11  12  13  14
**
**   next if we call list_get(&list, 0), it will return value of index 6.
**
**
**
** If we rotate again, anchor value will increase too.
**
**                     (Anchor = 2)
**            +---+---+---+---+---+---+---+
** Buffer:    | 2 | 1 | 3 | 5 | 7 | 9 | 0 |
**            +---+---+---+---+---+---+---+
** RealIndex:   0   1   2   3   4   5   6
** ListIndex:  -5  -4  -3  -2  -1   0   1
**              2   3   4   5   6   7   8
**              9  10  11  12  13  14  15
*/

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
