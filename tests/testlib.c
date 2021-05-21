/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testlib.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smun <smun@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 16:15:05 by smun              #+#    #+#             */
/*   Updated: 2021/04/19 17:28:00 by smun             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testlib.h"
#include <unistd.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define RESET "\033[0m"

static void		apply_result(int print, int status, const char *module_name)
{
	static int	total;
	static int	failed;

	if (print)
	{
		printf(RESET"[v] "YELLOW"%22s"RESET" RESULT\n", module_name);
		printf(" - "CYAN"TOTAL:                 [%6d]\n", total);
		printf(" - "GREEN"SUCCESS:               [%6d]\n", total - failed);
		printf(" - "RED"FAILED:                [%6d]\n", failed);
		printf(WHITE"-------------------------------------"RESET"\n");
	}
	else
	{
		total++;
		if (status != EXIT_SUCCESS)
			failed++;
	}
}

void			print_test_result(int argc, const char *module_name)
{
	(void)argc;
	apply_result(1, 0, module_name);
}

/*
** Do some test with a new child process.
** Returns its last status code.
*/

int				do_test(void(*testfunc)())
{
	int			status;
	pid_t		pid;

	pid = fork();
	if (!pid)
	{
		write(STDOUT_FILENO, RED, 5);
		testfunc();
		write(STDOUT_FILENO, RESET, 4);
		exit(EXIT_SUCCESS);
	}
	waitpid(pid, &status, 0);
	apply_result(0, status, NULL);
	return (status);
}
