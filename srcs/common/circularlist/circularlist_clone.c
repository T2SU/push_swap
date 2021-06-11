/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circularlist_clone.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 02:06:59 by smun              #+#    #+#             */
/*   Updated: 2021/06/12 02:27:38 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include <stdlib.h>

t_bool				circularlist_clone(t_circularlist *from, t_circularlist *to)
{
	const size_t	clone_size = from->capacity * sizeof(int);

	circularlist_free(to);
	to->values = malloc(clone_size);
	if (!to->values)
		return (FALSE);
	ft_memcpy(to->values, from->values, clone_size);
	to->anchor = from->anchor;
	to->capacity = from->capacity;
	to->length = from->length;
	return (TRUE);
}
