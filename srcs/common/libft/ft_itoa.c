/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 20:11:54 by smun              #+#    #+#             */
/*   Updated: 2021/06/29 18:29:00 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include <stdlib.h>

static char		*convert(char *b, int n)
{
	if (n / 10)
		b = convert(b, n / 10);
	*b = '0' + ft_abs(n % 10);
	return (b + 1);
}

char			*ft_itoa(int n)
{
	char		buf[32];
	char		*a;

	ft_bzero(buf, 32);
	if (n < 0)
		buf[0] = '-';
	convert(&buf[n < 0], n);
	if ((a = malloc(1 + ft_strlen(buf))))
		ft_strlcpy(a, buf, 1 + ft_strlen(buf));
	return (a);
}
