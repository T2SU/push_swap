/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_anchor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 14:11:38 by smun              #+#    #+#             */
/*   Updated: 2021/06/30 08:33:30 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void		list_tidy_up_anchor(t_list *list)
{
	if (list->anchor < 0)
	{
		if (list->length > 0)
			list->anchor += list->length;
		else
			list->anchor = 0;
	}
	if (list->anchor >= list->length)
	{
		if (list->length > 0)
			list->anchor %= list->length;
		else
			list->anchor = 0;
	}
}
