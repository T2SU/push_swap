/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 01:55:34 by smun              #+#    #+#             */
/*   Updated: 2021/06/12 02:40:10 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	list_rotate(t_list *list)
{
	list->anchor++;
}

void	list_reverse_rotate(t_list *list)
{
	list->anchor--;
}
