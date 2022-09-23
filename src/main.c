/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twinters <twinters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 11:24:55 by twinters          #+#    #+#             */
/*   Updated: 2022/09/23 12:28:48 by twinters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"
# include <stdio.h>

//creer un programme qui execute une commande puis affiche le pid

#include <sys/types.h>
#include <sys/wait.h>

int	main(int argc, char *argv[], char *env[])
{
	pid_t	pid;
	int		status;

	if (argc > 1)
	{
		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			return (1);
		}
		else if (pid == 0)
		{
			if (execve(argv[1], argv + 1, env) == -1)
				perror("execve");
			return (1);
		}
			wait(&status);
			printf("Status = %d\n", status);
		}
	printf("My pid is: %d\n", getpid());
	return (0);
}

// int main(int argc, char **argv, char **envp)
// {
// 	pid_t	pid1;

// 	pid1 = fork();
// 	if (pid1 == -1)
// 			return (1);
// 	else if (pid1 == 0)
// 		printf("voici mon pid : %d\n", getpid());
// 	else
// 		execve(argv[1], argv + 1, envp);
// }
