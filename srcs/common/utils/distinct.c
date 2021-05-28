/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distinct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 15:04:01 by smun              #+#    #+#             */
/*   Updated: 2021/05/28 18:41:46 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

t_bool			is_all_distinct(t_circularlist *list)
{
	int			i;
	int			j;

	i = -1;
	while (++i < list->length)
	{
		j = i;
		while (++j < list->length)
			if (list->values[i] == list->values[j])
				return (FALSE);
	}
	return (TRUE);
}
