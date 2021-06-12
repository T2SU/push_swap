/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 01:31:40 by smun              #+#    #+#             */
/*   Updated: 2021/06/13 01:33:36 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include <stdlib.h>
#include <unistd.h>

void		raise_error(const char *des)
{
	write(STDERR_FILENO, "Error\n", 6);
	if (des != NULL)
	{
		write(STDERR_FILENO, des, ft_strlen(des));
		write(STDERR_FILENO, "\n", 1);
	}
	exit(EXIT_FAILURE);
}
