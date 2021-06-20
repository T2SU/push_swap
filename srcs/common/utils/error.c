/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 01:31:40 by smun              #+#    #+#             */
/*   Updated: 2021/06/21 06:56:40 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include <stdlib.h>
#include <unistd.h>

/*
** if (des != NULL)
** {
** 	print_error(des);
** 	if (desc != NULL)
** 	{
** 		print_error(": ");
** 		print_error(desc);
** 	}
** 	print_error("\n");
** }
*/

void		raise_error_description(const char *des, const char *desc)
{
	print_error("Error\n");
	(void)des;
	(void)desc;
	exit(EXIT_FAILURE);
}

void		raise_error(const char *des)
{
	raise_error_description(des, NULL);
}
