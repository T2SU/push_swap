/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_strict.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 15:16:26 by smun              #+#    #+#             */
/*   Updated: 2021/05/28 17:50:46 by smun             ###   ########.fr       */
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
*/

t_bool			ft_atoi_strict(const char *str, int *pvalue)
{
	size_t		len;
	size_t		i;
	t_bool		neg;
	int			temp;

	if (chrcnt(str, '-') >= 2)
		return (FALSE);
	neg = str[0] == '-';
	if (neg)
		str++;
	len = ft_strlen(str);
	i = 0;
	temp = 0;
	while (i < len)
	{
		if (str[i] < '0' || str[i] > '9')
			return (FALSE);
		temp = (str[i++] - '0') + 10 * temp;
	}
	*pvalue = temp;
	return (TRUE);
}
