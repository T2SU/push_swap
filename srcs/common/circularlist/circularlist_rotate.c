/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circularlist_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 01:55:34 by smun              #+#    #+#             */
/*   Updated: 2021/05/28 18:41:46 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	circularlist_rotate(t_circularlist *list)
{
	list->anchor++;
}

void	circularlist_reverse_rotate(t_circularlist *list)
{
	list->anchor--;
}
