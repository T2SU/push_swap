/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 01:56:26 by smun              #+#    #+#             */
/*   Updated: 2021/04/11 01:59:12 by smun             ###   ########.fr       */
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
	int			trimmed_anchor;
	int			*ptr;
	int			move_size;

	trimmed_anchor = circulate_int(list->anchor, list->length);
	if (!ensure_list_size(list, list->length + 1))
		return (FALSE);
	ptr = list->values;
	move_size = list->length - trimmed_anchor;
	move_size *= sizeof(int);
	if (move_size > 0)
		ft_memmove(&ptr[trimmed_anchor + 1], &ptr[trimmed_anchor], move_size);
	ptr[trimmed_anchor] = value;
	list->length++;
	if (list->anchor < 0)
		list->anchor--;
	return (TRUE);
}
