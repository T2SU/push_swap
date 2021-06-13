/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 16:26:25 by smun              #+#    #+#             */
/*   Updated: 2021/06/14 03:02:57 by smun             ###   ########.fr       */
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

void		list_print(t_list *list)
{
	int		i;
	int		array_index;
	char	*a;

	i = 0;
	while (i < list->length)
	{
		array_index = list_get_real_index(list, i + list->anchor);
		if ((a = ft_itoa(list->values[array_index])))
		{
			print(a);
			free(a);
		}
		else
			print("?");
		print(" ");
		i++;
	}
	print("\n");
}

void		list_free(t_list *list)
{
	free(list->values);
	list->values = NULL;
	list->capacity = 0;
	list->length = 0;
	list->anchor = 0;
}

int				list_get_fastest_distance(t_list *list, int value)
{
	int			forward_value;
	int			backward_value;
	int			i;

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
