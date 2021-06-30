/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 16:26:25 by smun              #+#    #+#             */
/*   Updated: 2021/06/30 13:26:48 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include <stdlib.h>

t_bool		list_init(t_list *list, int length)
{
	if (length > 0)
	{
		list->values = malloc(sizeof(int) * length);
		if (!list->values)
			return (FALSE);
		list->capacity = length;
	}
	else
	{
		list->values = NULL;
		list->capacity = 0;
	}
	list->anchor = 0;
	list->length = 0;
	return (TRUE);
}

void		list_free(t_list *list)
{
	free(list->values);
	list->values = NULL;
	list->capacity = 0;
	list->length = 0;
	list->anchor = 0;
}

int			list_get_fastest_distance(t_list *list, int value)
{
	int		forward_value;
	int		backward_value;
	int		i;

	i = 0;
	while (i < list->length)
	{
		forward_value = list_get(list, i);
		backward_value = list_get(list, -i);
		if (forward_value == value)
			return (i);
		if (backward_value == value)
			return (-i);
		i++;
	}
	return (0);
}
