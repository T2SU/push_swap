/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 16:26:55 by smun              #+#    #+#             */
/*   Updated: 2021/05/21 12:27:22 by smun             ###   ########.fr       */
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
}				t_list;

t_bool			list_init(t_list *list, int length);
void			list_free(t_list *list);
int				list_get(t_list *list, int index);
void			list_set(t_list *list, int index, int value);
t_bool			list_push_one(t_list *list, int value);
int				list_pop_one(t_list *list);
void			list_rotate(t_list *list);
void			list_reverse_rotate(t_list *list);
void			list_print(t_list *list);

int				circulate_int(int value, int point);
int				ft_abs(int n);
char			*ft_itoa(int n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			ft_bzero(void *s, size_t n);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t			ft_strlen(const char *s);

#endif
