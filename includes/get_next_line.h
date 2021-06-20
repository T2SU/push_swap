/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 10:56:59 by smun              #+#    #+#             */
/*   Updated: 2021/06/21 05:30:06 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include "common.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128
# endif

# ifndef LINE_SEPARATOR
#  define LINE_SEPARATOR '\n'
# endif

# ifndef FD_MAX
#  define FD_MAX 256
# endif

/*
** ============================================================================
**    Enums
** ============================================================================
*/

enum			e_status
{
	kStatusError = -1,
	kStatusContinue = 0,
	kStatusFoundLine = 1,
	kStatusEOF = 2
};

enum			e_return
{
	kReturnError = -1,
	kReturnEOF = 0,
	kReturnFoundLine = 1
};

/*
** ============================================================================
**   Structures / Unions
** ============================================================================
*/

typedef struct	s_reader
{
	char		*buffer;
	ssize_t		len;
	t_bool		eof;
}				t_reader;

/*
** ============================================================================
**   Functions
** ============================================================================
*/

/*
**  get_next_line.c
*/

int				get_next_line(int fd, char **line);

#endif
