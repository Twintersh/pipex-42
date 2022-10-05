/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twinters <twinters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 11:24:55 by twinters          #+#    #+#             */
/*   Updated: 2022/10/05 11:43:31 by twinters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static void	ft_close(t_data *pipex)
{
	close(pipex->pipe[0]);
	close(pipex->pipe[1]);
	close(pipex->infile);
	close(pipex->outfile);
	ft_str_free(pipex->c->cmd1);
	ft_str_free(pipex->c->cmd2);
	free(pipex->c);
	free(pipex);
}

static void	split_cmds(t_data *pipex)
{
	pipex->c->cmd1 = ft_split(pipex->args[2], ' ');
	pipex->c->cmd2 = ft_split(pipex->args[3], ' ');
}

void	check_errors(t_data *pipex, int pipe_value)
{
	if (pipex->infile < 0)
		ft_printf("%s : bad file descriptor\n", pipex->args[1]);
	if (pipex->outfile < 0)
		msg_exit("File descriptor outfile error\n");
	if (pipe_value < 0)
		msg_exit("Pipe error\n");
}

void	msg_exit(char *str)
{
	ft_putstr(str);
	exit(EXIT_FAILURE);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_data	*pipex;
	int		pipe_value;

	if (argc != 5)
		msg_exit("Invalid number of arguments\n");
	pipex = init_pipex(argv, envp);
	pipex->infile = open(argv[1], O_RDONLY);
	pipex->outfile = open(argv[4], O_TRUNC ^ O_CREAT ^ O_WRONLY, 0664);
	pipe_value = pipe(pipex->pipe);
	check_errors(pipex, pipe_value);
	split_cmds(pipex);
	if (pipex->infile >= 0)
		fst_command(pipex, get_cmd_path(pipex->c->cmd1[0], pipex->envp));
	snd_command(pipex, get_cmd_path(pipex->c->cmd2[0], pipex->envp));
	ft_close(pipex);
	return (0);
}
