/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twinters <twinters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 16:01:53 by twinters          #+#    #+#             */
/*   Updated: 2022/10/04 14:52:51 by twinters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

t_data	*init_pipex(char **argv, char **envp)
{
	t_data	*pipex;

	pipex = malloc(sizeof(t_data));
	if (!pipex)
		error_msg("Pipex malloc error\n", NULL);
	pipex->args = argv;
	pipex->envp = envp;
	pipex->infile = -1;
	pipex->outfile = -1;
	pipex->cmd_args = NULL;
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
	str = NULL;
}

void	error_msg(char *str, t_data *pipex)
{
	if (pipex)
	{
		if (pipex->pipe[0] >= 0)
			close(pipex->pipe[0]);
		if (pipex->pipe[1] >= 0)
			close(pipex->pipe[1]);
		if (pipex->infile >= 0)
			close(pipex->infile);
		if (pipex->outfile >= 0)
			close(pipex->outfile);
		if (pipex->cmd_args)
			ft_str_free(pipex->cmd_args);
		free(pipex);
	}
	ft_putstr(str);
	exit(EXIT_FAILURE);
}

void	fst_command(t_data *pipex)
{
	char	*cmd_p;

	pipex->cmd_args = ft_split(pipex->args[2], ' ');
	cmd_p = get_cmd_path(pipex->cmd_args[0], pipex->envp, pipex);
	pipex->pid1 = fork();
	if (pipex->pid1 < 0)
		error_msg("Fork fst command error", pipex);
	if (pipex->pid1 == CHILD)
	{
		dup2(pipex->pipe[PIPE_IN], STDOUT_FILENO);
		dup2(pipex->infile, STDIN_FILENO);
		close(pipex->pipe[PIPE_IN]);
		close(pipex->pipe[PIPE_OUT]);
		close(pipex->infile);
		execve(cmd_p, pipex->cmd_args, pipex->envp);
		exit(EXIT_SUCCESS);
	}
	waitpid(pipex->pid1, NULL, 0);
	free(cmd_p);
	ft_str_free (pipex->cmd_args);
}

void	snd_command(t_data *pipex)
{
	char	*cmd_p;

	pipex->cmd_args = ft_split(pipex->args[3], ' ');
	cmd_p = get_cmd_path(pipex->cmd_args[0], pipex->envp, pipex);
	pipex->pid2 = fork();
	if (pipex->pid2 < 0)
		error_msg("Fork snd command error", pipex);
	if (pipex->pid2 == CHILD)
	{
		dup2(pipex->pipe[PIPE_OUT], STDIN_FILENO);
		dup2(pipex->outfile, STDOUT_FILENO);
		close(pipex->pipe[PIPE_OUT]);
		close(pipex->pipe[PIPE_IN]);
		close(pipex->outfile);
		execve(cmd_p, pipex->cmd_args, pipex->envp);
		exit(EXIT_SUCCESS);
	}
	free(cmd_p);
	ft_str_free(pipex->cmd_args);
}
