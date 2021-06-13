/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:05:07 by smun              #+#    #+#             */
/*   Updated: 2021/06/13 19:14:19 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include <unistd.h>

static void	print_fd(int fd, const char *str)
{
	write(fd, str, ft_strlen(str));
}

/*
** equivalent with ft_putstr
*/

void		print(const char *str)
{
	print_fd(STDOUT_FILENO, str);
}

void		print_error(const char *str)
{
	print_fd(STDERR_FILENO, str);
}
