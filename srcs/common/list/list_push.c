/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 01:56:26 by smun              #+#    #+#             */
/*   Updated: 2021/06/12 02:42:03 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include <stdlib.h>

static t_bool	ensure_list_size(t_list *list, int size)
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

t_bool			list_push_one(t_list *list, int value)
{
	int			idx;
	int			*ptr;
	int			move_size;

	idx = list_get_real_index(list, list->anchor);
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