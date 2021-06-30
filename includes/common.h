/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 16:26:55 by smun              #+#    #+#             */
/*   Updated: 2021/06/30 10:25:25 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include <stddef.h>
# include <unistd.h>
# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define FALSE 0
# define TRUE 1
# define A_TO_B 0
# define B_TO_A 1

enum			e_numberflag
{
	kHasHigher = 1 << 0,
	kHasLower = 1 << 1
};

enum			e_positive
{
	kPositive,
	kNegative,
	kZero
};

enum			e_order
{
	kAscending,
	kDescending
};

enum			e_target
{
	kFrom,
	kTo,
	kTargetNum
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

t_route			calculate_route(t_list *a, t_list *b, int value, int dir);
void			print_instructions_by_route(t_route route);
void			apply_distance_to_list(t_list *list, int distance);

/*
**  ===========================================
**      srcs/common/list/list.c
**  ===========================================
*/

t_bool			list_init(t_list *list, int length);
void			list_print(t_list *list);
void			list_free(t_list *list);
int				list_get_fastest_distance(t_list *list, int value);

/*
**  ===========================================
**      srcs/common/list/list_getset.c
**  ===========================================
*/

int				list_get_real_index(t_list *list, int index);
void			list_tidy_up_anchor(t_list *list);
int				list_get(t_list *list, int index);
void			list_set(t_list *list, int index, int value);
int				list_get_highest_number(t_list *list, int basis);
int				list_get_lowest_number(t_list *list, int basis);

/*
**  ===========================================
**      srcs/common/list/list_push.c
**  ===========================================
*/

t_bool			list_push_one(t_list *list, int value);
t_bool			list_push(t_list *list_a, t_list *list_b, int dir);
t_bool			list_push_and_print(t_list *list_a, t_list *list_b, int dir);

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

void			list_reverse_rotate(t_list *list);
void			list_rotate(t_list *list);
void			list_rotate_order_by(t_list *list_a, t_list *list_b, int order);

/*
**  ===========================================
**      srcs/common/list/list_clone.c
**  ===========================================
*/

t_bool			list_is_sorted(t_list *list, int order);

/*
**  ===========================================
**      srcs/common/list/list_swap.c
**  ===========================================
*/

t_bool			list_swap(t_list *list, const char *instruction);

/*
**  ===========================================
**      srcs/common/list/list_find_unsorted.c
**  ===========================================
*/

t_bool			list_find_unsorted_biggest(t_list *list, int *pvalue);

/*
**  ===========================================
**      srcs/common/utils/distinct.c
**  ===========================================
*/

t_bool			is_all_distinct(t_list *list);

/*
**  ===========================================
**      srcs/common/utils/error.c
**  ===========================================
*/

void			raise_error(const char *des);
void			raise_error_description(const char *des, const char *desc);

/*
**  ===========================================
**      srcs/common/utils/print.c
**  ===========================================
*/

void			print(const char *str);
void			print_error(const char *str);

/*
**  ===========================================
**      srcs/common/parser.c
**  ===========================================
*/

void			parse_into_list(t_list *list, int argc, char *argv[]);

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
ssize_t			ft_indexof(const char *s, int c, size_t len);
int				ft_strcmp(const char *s1, const char *s2);
char			**ft_split(const char *s, char c);

#endif
