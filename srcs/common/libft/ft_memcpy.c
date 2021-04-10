/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 14:24:54 by smun              #+#    #+#             */
/*   Updated: 2021/04/11 01:31:46 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void					*ft_memcpy(void *dst, const void *src, size_t n)
{
	const unsigned char	*source = (const unsigned char*)src;
	unsigned char		*dest;
	size_t				*source_large;
	size_t				*dest_large;
	size_t				i;

	if (src || dst)
	{
		dest = (unsigned char*)dst;
		if ((i = n % sizeof(size_t)))
		{
			while (i--)
				*(dest++) = *(source++);
		}
		if ((i = n / sizeof(size_t)))
		{
			source_large = (size_t*)source;
			dest_large = (size_t*)dest;
			while (i--)
				*(dest_large++) = *(source_large++);
		}
	}
	return (dst);
}
