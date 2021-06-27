/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:43:41 by smun              #+#    #+#             */
/*   Updated: 2021/06/27 16:10:44 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include <stdlib.h>

static void		parse_number(t_list *list, char *arg, int index, int length)
{
	char		*tmp;
	int			num;

	if (NULL == (tmp = malloc(length + 1)))
		raise_error("out of memory");
	ft_memcpy(tmp, &arg[index], length);
	tmp[length] = '\0';
	if (!ft_atoi_strict(tmp, &num))
		raise_error_description("unparsable into integer.", tmp);
	list_push_one(list, num);
	free(tmp);
}

static void		parse_element(t_list *list, char *arg)
{
	int			i;
	int			index;
	int			length;

	i = 0;
	index = 0;
	length = 0;
	while (TRUE)
	{
		if (arg[i] == ' ' || arg[i] == '\0')
		{
			parse_number(list, &arg[i], index, length);
			index += length + 1;
			length = 0;
		}
		if (arg[i++] == '\0')
			break ;
		length++;
	}
}

void			parse_into_list(t_list *list, int argc, char *argv[])
{
	const int	start_index = 1;
	int			i;
	int			num;

	if (argc <= start_index)
		raise_error("lacked arguments.");
	i = argc - 1;
	while (i >= start_index)
		parse_element(list, argv[i--]);
}
