/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 16:26:55 by smun              #+#    #+#             */
/*   Updated: 2021/05/28 18:37:04 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include <stddef.h>

enum			e_bool
{
	FALSE,
	TRUE
};

typedef int		t_bool;

typedef struct	s_list
{
	int			*values;
	int			anchor;
	int			length;
	int			capacity;
}				t_circularlist;

/*
**  ===========================================
**      srcs/common/circularlist/circularlist.c
**  ===========================================
*/

t_bool			circularlist_init(t_circularlist *list, int length);
void			circularlist_print(t_circularlist *list);
void			circularlist_free(t_circularlist *list);

/*
**  ===========================================
**      srcs/common/circularlist/circularlist_getset.c
**  ===========================================
*/

int				circularlist_get_real_index(t_circularlist *list, int index);
int				circularlist_get(t_circularlist *list, int index);
void			circularlist_set(t_circularlist *list, int index, int value);

/*
**  ===========================================
**      srcs/common/circularlist/circularlist_push.c
**  ===========================================
*/

t_bool			circularlist_push_one(t_circularlist *list, int value);

/*
**  ===========================================
**      srcs/common/circularlist/circularlist_pop.c
**  ===========================================
*/

int				circularlist_pop_one(t_circularlist *list);

/*
**  ===========================================
**      srcs/common/circularlist/circularlist_rotate.c
**  ===========================================
*/

void			circularlist_rotate(t_circularlist *list);
void			circularlist_reverse_rotate(t_circularlist *list);

/*
**  ===========================================
**      srcs/common/utils/distinct.c
**  ===========================================
*/

t_bool			is_all_distinct(t_circularlist *list);

int				circulate_int(int value, int point);
int				ft_abs(int n);
t_bool			ft_atoi_strict(const char *str, int *pvalue);
char			*ft_itoa(int n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			ft_bzero(void *s, size_t n);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t			ft_strlen(const char *s);

#endif
