/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 01:50:42 by smun              #+#    #+#             */
/*   Updated: 2021/06/18 23:48:23 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "common.h"

/*
**  ===========================================
**      srcs/push_swap/navigator.c
**  ===========================================
*/

t_bool		navigate(t_list *list_a, t_list *list_b);
t_route		find_route_by_lowest_cost(t_list *list_a, t_list *list_b, int dir);

/*
**  ===========================================
**      srcs/push_swap/parser.c
**  ===========================================
*/

void		parse_into_list(t_list *list, int argc, char *argv[]);

/*
**  ===========================================
**      srcs/push_swap/game.c
**  ===========================================
*/

void		do_game(t_list *list_a, t_list *list_b, int argc, char *argv[]);

#endif
