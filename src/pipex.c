/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twinters <twinters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 16:01:53 by twinters          #+#    #+#             */
/*   Updated: 2022/10/02 11:49:44 by twinters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

// Check how works the fonction dup2.
// I don't really understand how it works
// on the snd command call i think it can solve the bug.
// good luck and focus

t_data	*init_pipex(char **argv, char **envp)
{
	t_data	*pipex;

	pipex = malloc(sizeof(t_data));
	if (!pipex)
		error_msg("Pipex malloc error\n");
	pipex->args = argv;
	pipex->envp = envp;
	pipex->infile = -1;
	pipex->outfile = -1;
	pipex->pid1 = 0;
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
}

void	error_msg(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

void	fst_command(t_data *pipex)
{
	char	**cmd_args;
	char	*cmd_p;

	cmd_args = ft_split(pipex->args[2], ' ');
	cmd_p = get_cmd_path(cmd_args[0], pipex->envp);
	pipex->pid1 = fork();
	if (pipex->pid1 < 0)
		error_msg("Fork fst command error");
	if (pipex->pid1 == CHILD)
	{
		dup2(pipex->pipe[PIPE_IN], STDOUT_FILENO);
		dup2(pipex->infile, STDIN_FILENO);
		close(pipex->pipe[PIPE_IN]);
		close(pipex->pipe[PIPE_OUT]);
		close(pipex->infile);
		execve(cmd_p, cmd_args, pipex->envp);
		exit(EXIT_SUCCESS);
	}
	waitpid(pipex->pid1, NULL, 0);
	free(cmd_p);
	ft_str_free(cmd_args);
}

void	snd_command(t_data *pipex)
{
	char	**cmd_args;
	char	*cmd_p;

	cmd_args = ft_split(pipex->args[3], ' ');
	cmd_p = get_cmd_path(cmd_args[0], pipex->envp);
	pipex->pid2 = fork();
	if (pipex->pid2 < 0)
		error_msg("Fork snd command error");
	if (pipex->pid2 == CHILD)
	{
		dup2(pipex->pipe[PIPE_OUT], STDIN_FILENO);
		dup2(pipex->outfile, STDOUT_FILENO);
		dup2(STDOUT_FILENO, pipex->outfile);
		close(pipex->pipe[PIPE_OUT]);
		close(pipex->pipe[PIPE_IN]);
		close(pipex->outfile);
		execve(cmd_p, cmd_args, pipex->envp);
		exit(EXIT_SUCCESS);
	}
	free(cmd_p);
	ft_str_free(cmd_args);
}
