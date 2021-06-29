/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_pop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 01:56:44 by smun              #+#    #+#             */
/*   Updated: 2021/06/29 17:40:02 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int					list_pop_one(t_list *list)
{
	int				move_size;
	int				idx;
	int				*ptr;
	int				value;

	if (list->length <= 0)
		return (0);
	idx = list_get_real_index(list, list->anchor);
	ptr = list->values;
	value = ptr[idx];
	move_size = list->length - idx;
	move_size *= sizeof(int);
	if (move_size > 0)
		ft_memmove(&ptr[idx], &ptr[idx + 1], move_size);
	list->length--;
	list_purge(list);
	return (value);
}
