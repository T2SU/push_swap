/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_strict.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 15:16:26 by smun              #+#    #+#             */
/*   Updated: 2021/06/13 01:39:17 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

/*
** Not parsable int?
**   1.  2 or more '-'
**   2.  too big or too small number ( < -2147483648  or  > 2147483647)
**   3.  non digit or dash
**   4.  only dash '-'
*/

t_bool			ft_atoi_strict(const char *str, int *pvalue)
{
	size_t		i;
	t_bool		neg;
	int			temp;

	neg = str[0] == '-';
	if (str[i = neg] == '\0')
		return (FALSE);
	*pvalue = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (FALSE);
		temp = str[i++] - '0';
		temp = 10 * *pvalue + (neg ? -temp : temp);
		if (temp != *pvalue && (temp < *pvalue) != neg)
			return (FALSE);
		*pvalue = temp;
	}
	return (TRUE);
}
