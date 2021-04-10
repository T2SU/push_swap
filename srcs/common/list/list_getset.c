/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_getset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 01:57:30 by smun              #+#    #+#             */
/*   Updated: 2021/04/11 01:57:37 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static	int			get_real_index(t_list *list, int index)
{
	int				trimmed_anchor;
	int				trimmed_index;
	int				sum;

	trimmed_anchor = circulate_int(list->anchor, list->length);
	trimmed_index = circulate_int(index, list->length);
	sum = trimmed_anchor + trimmed_index;
	return (circulate_int(sum, list->length));
}

int					list_get(t_list *list, int index)
{
	return (list->values[get_real_index(list, index)]);
}

void				list_set(t_list *list, int index, int value)
{
	list->values[get_real_index(list, index)] = value;
}
