/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_remove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 01:56:44 by smun              #+#    #+#             */
/*   Updated: 2021/04/11 01:56:50 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int					list_pop_one(t_list *list)
{
	int				move_size;
	int				trimmed_anchor;
	int				*ptr;
	int				value;

	if (list->length <= 0)
		return (0);
	trimmed_anchor = circulate_int(list->anchor, list->length);
	ptr = list->values;
	move_size = list->length - trimmed_anchor;
	move_size *= sizeof(int);
	value = ptr[trimmed_anchor];
	if (move_size > 0)
		ft_memmove(&ptr[trimmed_anchor], &ptr[trimmed_anchor + 1], move_size);
	list->length--;
	if (list->anchor < 0)
		list->anchor++;
	return (value);
}
