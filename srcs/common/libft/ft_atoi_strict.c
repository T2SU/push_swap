/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_strict.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 15:16:26 by smun              #+#    #+#             */
/*   Updated: 2021/05/28 20:26:36 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static size_t	chrcnt(const char *str, char ch)
{
	size_t		ret;

	ret = 0;
	while (*str)
	{
		if (*str == ch)
			ret++;
		str++;
	}
	return (ret);
}

/*
** Non parsable int?
**   1.  2 or more '-'
**   2.  too big or too small number ( < -2147483648  or  > 2147483647)
**   3.  non digit or dash
**   4.  only dash '-'
*/

t_bool			ft_atoi_strict(const char *str, int *pvalue)
{
	size_t		i;
	t_bool		neg;
	int			digit;
	int			temp;

	if (chrcnt(str, '-') >= 2 || str[0] == '\0')
		return (FALSE);
	neg = str[0] == '-';
	i = neg;
	if (str[i] == '\0')
		return (FALSE);
	*pvalue = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (FALSE);
		digit = (str[i++] - '0');
		digit *= neg ? -1 : 1;
		temp = 10 * *pvalue + digit;
		if (temp != *pvalue && (temp < *pvalue) != neg)
			return (FALSE);
		*pvalue = temp;
	}
	return (TRUE);
}
