/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circularlist_push.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 01:56:26 by smun              #+#    #+#             */
/*   Updated: 2021/05/28 18:41:46 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include <stdlib.h>

static t_bool	ensure_list_size(t_circularlist *list, int size)
{
	int			*new_buffer;

	if (size < 0)
		return (FALSE);
	if (list->capacity >= size)
		return (TRUE);
	new_buffer = malloc(sizeof(int) * size);
	if (!new_buffer)
		return (FALSE);
	if (list->values)
	{
		ft_memcpy(new_buffer, list->values, list->length * sizeof(int));
		free(list->values);
	}
	list->values = new_buffer;
	list->capacity++;
	return (TRUE);
}

t_bool			circularlist_push_one(t_circularlist *list, int value)
{
	int			idx;
	int			*ptr;
	int			move_size;

	idx = circularlist_get_real_index(list, list->anchor);
	if (!ensure_list_size(list, list->length + 1))
		return (FALSE);
	ptr = list->values;
	move_size = list->length - idx;
	move_size *= sizeof(int);
	if (move_size > 0)
		ft_memmove(&ptr[idx + 1], &ptr[idx], move_size);
	ptr[idx] = value;
	if (list->anchor < 0)
		list->anchor--;
	else if (list->length <= list->anchor)
		list->anchor++;
	list->length++;
	return (TRUE);
}
