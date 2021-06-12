/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 16:26:25 by smun              #+#    #+#             */
/*   Updated: 2021/06/13 01:49:45 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include <stdlib.h>
#include <unistd.h>

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

void		print(const char *prefix, t_list *list)
{
	write(STDOUT_FILENO, prefix, ft_strlen(prefix));
	write(STDOUT_FILENO, ": ", 2);
	list_print(list);
}

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
			write(STDOUT_FILENO, a, ft_strlen(a));
			free(a);
		}
		else
			write(STDOUT_FILENO, "?", 1);
		write(STDOUT_FILENO, " ", 1);
		i++;
	}
	write(STDOUT_FILENO, "\n", 1);
}

void		list_free(t_list *list)
{
	free(list->values);
	list->values = NULL;
	list->capacity = 0;
	list->length = 0;
	list->anchor = 0;
}
