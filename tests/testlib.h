/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testlib.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 16:14:46 by smun              #+#    #+#             */
/*   Updated: 2021/06/13 14:50:33 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTLIB_H
# define TESTLIB_H

# define do_test_stdout(testfunc, compare_str) \
	do_test_stdout_real(testfunc, __FILE__, __LINE__, compare_str)

void		print_test_result(int argc, const char *module_name);
int			do_test(void(*testfunc)());
int			do_test_stdout_real(void(*testfunc)(), const char *file, int line, const char *compare);

#endif
