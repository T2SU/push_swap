/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 23:34:41 by smun              #+#    #+#             */
/*   Updated: 2021/06/21 08:45:15 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

t_bool		list_swap(t_list *list, const char *instruction)
{
	int		temp;

	if (list->length <= 1)
		return (FALSE);
	temp = list_get(list, 0);
	list_set(list, 0, list_get(list, 1));
	list_set(list, 1, temp);
	if (instruction != NULL)
	{
		print(instruction);
		print("\n");
	}
	return (TRUE);
}
