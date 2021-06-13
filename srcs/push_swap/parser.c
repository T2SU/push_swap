/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:43:41 by smun              #+#    #+#             */
/*   Updated: 2021/06/13 19:56:53 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			parse_into_list(t_list *list, int argc, char *argv[])
{
	const int	start_index = 1;
	int			i;
	int			num;

	if (argc <= start_index)
		raise_error("lacked arguments.");
	i = argc - 1;
	while (i >= start_index)
	{
		if (!ft_atoi_strict(argv[i], &num))
			raise_error_description("unparsable into integer.", argv[i]);
		list_push_one(list, num);
		i--;
	}
}
