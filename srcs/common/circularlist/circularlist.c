/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circularlist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 16:26:25 by smun              #+#    #+#             */
/*   Updated: 2021/05/28 18:40:48 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include <stdlib.h>
#include <unistd.h>

t_bool		circularlist_init(t_circularlist *list, int length)
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

/*
**  Example:
**    1. Anchor=7,  index=-3,   length=4
**       - Anchor = 7 % 4 = 3
**                => 3
**       - index  = -3 % 4 = -3
**                => -3 + 4 = 1
**                => 1
**       - Anchor + index = 3 + 1 = 4
**                        => 4 % 4 = 0
**                        => 0
**       - RealIndex = 0
*/

void		print(const char *prefix, t_circularlist *list)
{
	write(1, prefix, ft_strlen(prefix));
	write(1, ": ", 2);
	circularlist_print(list);
}

void		circularlist_print(t_circularlist *list)
{
	int		i;
	int		array_index;
	char	*a;

	i = 0;
	while (i < list->length)
	{
		array_index = circularlist_get_real_index(list, i + list->anchor);
		a = ft_itoa(list->values[array_index]);
		if (!a)
			continue;
		write(1, a, ft_strlen(a));
		free(a);
		write(1, " ", 1);
		i++;
	}
	write(1, "\n", 1);
}

void		circularlist_free(t_circularlist *list)
{
	free(list->values);
	list->values = NULL;
	list->capacity = 0;
	list->length = 0;
	list->anchor = 0;
}
