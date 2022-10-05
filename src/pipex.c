/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twinters <twinters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 16:01:53 by twinters          #+#    #+#             */
/*   Updated: 2022/10/05 11:48:43 by twinters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

t_data	*init_pipex(char **argv, char **envp)
{
	t_data	*pipex;

	pipex = malloc(sizeof(t_data));
	if (!pipex)
	{
		ft_putstr("Malloc Error\n");
		exit(EXIT_FAILURE);
	}
	pipex->c = malloc(sizeof(t_commands));
	if (!pipex->c)
	{
		ft_putstr("Malloc Error\n");
		exit(EXIT_FAILURE);
	}
	pipex->c->cmd1 = NULL;
	pipex->c->cmd2 = NULL;
	pipex->args = argv;
	pipex->envp = envp;
	return (pipex);
}

void	ft_str_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	str = NULL;
}

void	fst_command(t_data *pipex, char *cmd_p)
{
	pid_t	pid1;

	if (!cmd_p)
		return ((void)ft_putstr("Error first command\n"));
	pid1 = fork();
	if (pid1 < 0)
		return ((void)ft_putstr("Error pid1\n"));
	if (pid1 == CHILD)
	{
		dup2(pipex->pipe[PIPE_IN], STDOUT_FILENO);
		dup2(pipex->infile, STDIN_FILENO);
		close(pipex->pipe[PIPE_IN]);
		close(pipex->pipe[PIPE_OUT]);
		close(pipex->infile);
		execve(cmd_p, pipex->c->cmd1, pipex->envp);
		exit(EXIT_SUCCESS);
	}
	waitpid(pid1, NULL, 0);
	free(cmd_p);
}

void	snd_command(t_data *pipex, char *cmd_p)
{
	pid_t	pid2;

	if (!cmd_p)
		return ((void)ft_putstr("Error 2nd command\n"));
	pid2 = fork();
	if (pid2 < 0)
		return ((void)ft_putstr("Error pid2\n"));
	if (pid2 == CHILD)
	{
		dup2(pipex->pipe[PIPE_OUT], STDIN_FILENO);
		dup2(pipex->outfile, STDOUT_FILENO);
		close(pipex->pipe[PIPE_OUT]);
		close(pipex->pipe[PIPE_IN]);
		close(pipex->outfile);
		execve(cmd_p, pipex->c->cmd2, pipex->envp);
		exit(EXIT_SUCCESS);
	}
	free(cmd_p);
}
