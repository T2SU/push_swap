/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_indexof.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 03:21:10 by smun              #+#    #+#             */
/*   Updated: 2021/06/19 03:21:47 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

ssize_t			ft_indexof(const char *s, int c, size_t len)
{
	ssize_t		i;

	if (s != NULL)
	{
		i = 0;
		while (i < (ssize_t)len)
		{
			if (s[i] == (char)c)
				return (i);
			i++;
		}
	}
	return (-1);
}
