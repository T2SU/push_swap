/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 20:13:06 by smun              #+#    #+#             */
/*   Updated: 2021/06/11 23:17:02 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static size_t	truncate_len(size_t slen, size_t dstsize)
{
	return ((slen >= dstsize) ? (dstsize - 1) : (slen));
}

size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t		slen;
	size_t		cpylen;

	slen = 0;
	if (src)
		slen = ft_strlen(src);
	if (dstsize > 0)
	{
		cpylen = truncate_len(slen, dstsize);
		ft_memcpy(dst, src, cpylen);
		if (dst)
			dst[cpylen] = '\0';
	}
	return (slen);
}

size_t			ft_strlen(const char *s)
{
	size_t		l;

	l = 0;
	while (s[l])
		l++;
	return (l);
}
