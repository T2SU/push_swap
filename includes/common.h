/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 16:26:55 by smun              #+#    #+#             */
/*   Updated: 2021/06/12 21:39:51 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include <stddef.h>
# define INT_MAX 2147483647
# define INT_MIN -2147483648

enum			e_bool
{
	FALSE,
	TRUE
};

enum			e_numberflag
{
	HAS_HIGHER = 1 << 0,
	HAS_LOWER = 1 << 1
};

typedef int		t_bool;

typedef struct	s_list
{
	int			*values;
	int			anchor;
	int			length;
	int			capacity;
}				t_list;

typedef struct	s_route
{
	int			distance_a;
	int			distance_b;
	int			total_cost;
}				t_route;

/*
**  ===========================================
**      srcs/common/route/route.c
**  ===========================================
*/

t_route			calculate_route(t_list *list_a, t_list *list_b, int value);

/*
**  ===========================================
**      srcs/common/list/list.c
**  ===========================================
*/

t_bool			list_init(t_list *list, int length);
void			list_print(t_list *list);
void			list_free(t_list *list);

/*
**  ===========================================
**      srcs/common/list/list_getset.c
**  ===========================================
*/

int				list_get_real_index(t_list *list, int index);
int				list_get(t_list *list, int index);
void			list_set(t_list *list, int index, int value);

/*
**  ===========================================
**      srcs/common/list/list_push.c
**  ===========================================
*/

t_bool			list_push_one(t_list *list, int value);

/*
**  ===========================================
**      srcs/common/list/list_pop.c
**  ===========================================
*/

int				list_pop_one(t_list *list);

/*
**  ===========================================
**      srcs/common/list/list_rotate.c
**  ===========================================
*/

void			list_rotate(t_list *list);
void			list_reverse_rotate(t_list *list);

/*
**  ===========================================
**      srcs/common/list/list_clone.c
**  ===========================================
*/

t_bool			list_clone(t_list *from, t_list *to);

/*
**  ===========================================
**      srcs/common/utils/distinct.c
**  ===========================================
*/

t_bool			is_all_distinct(t_list *list);

/*
** libft
*/

int				ft_abs(int n);
t_bool			ft_atoi_strict(const char *str, int *pvalue);
t_bool			ft_isneg(int i);
char			*ft_itoa(int n);
int				ft_max(int a, int b);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			ft_bzero(void *s, size_t n);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t			ft_strlen(const char *s);

#endif
