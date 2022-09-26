/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twinters <twinters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:30:38 by twinters          #+#    #+#             */
/*   Updated: 2022/09/26 11:59:52 by twinters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char	*arg_1[] = {"ping", "google.com", NULL};
	char	*arg_2[] = {"grep", "-o", "rtt", NULL};
	int		end[2];
	int		pid[2];

	pid[0] = fork();
	if (pid[0] == 0)
	{
		printf("fils [%d]\n", getpid());
		execve("/usr/bin/ping", arg_1, NULL);
	}
	else
	{
		printf("daron[%d]\n", getpid());
		waitpid(pid[0], NULL, 0);
	}
	pid[1] = fork();
	if (pid[1] == 0)
	{
		printf("fils [%d]\n", getpid());
		execve("/usr/bin/grep", arg_2, NULL);
	}
	else
	{
		printf("daron[%d]\n", getpid());
		waitpid(pid[1], NULL, 0);
	}


	return (0);
}
