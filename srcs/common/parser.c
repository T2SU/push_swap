/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:43:41 by smun              #+#    #+#             */
/*   Updated: 2021/06/28 13:41:36 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include <stdlib.h>

static int		get_size_of_vector(const char **vector)
{
	int			i;

	i = 0;
	while (vector[i] != NULL)
		i++;
	return (i);
}

static void		parse_element(t_list *list, const char *arg)
{
	const char	**splitted = (const char**)ft_split(arg, ' ');
	int			i;
	int			num;

	if (splitted == NULL)
		raise_error("out of memory");
	i = get_size_of_vector(splitted);
	while (--i >= 0)
	{
		if (!ft_atoi_strict(splitted[i], &num))
			raise_error_description("unparsable into integer.", splitted[i]);
		list_push_one(list, num);
		free((void*)splitted[i]);
	}
	free(splitted);
}

void			parse_into_list(t_list *list, int argc, char *argv[])
{
	const int	start_index = 1;
	int			i;

	if (argc <= start_index)
		raise_error("lacked arguments.");
	i = argc - 1;
	while (i >= start_index)
		parse_element(list, argv[i--]);
}
