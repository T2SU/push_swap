/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circular.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 19:57:16 by smun              #+#    #+#             */
/*   Updated: 2021/04/11 01:31:53 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int			circulate_int(int value, int point)
{
	int		trimmed_value;

	trimmed_value = value;
	if (point)
		trimmed_value %= point;
	if (trimmed_value < 0)
		trimmed_value += point;
	return (trimmed_value);
}
