/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 01:45:24 by smun              #+#    #+#             */
/*   Updated: 2021/06/20 01:46:53 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	while ((*s1 || *s2))
	{
		if (*s1 != *s2)
			return ((unsigned char)(*s1) - (unsigned char)(*s2));
		s1++;
		s2++;
	}
	return (0);
}
