/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twinters <twinters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 11:24:55 by twinters          #+#    #+#             */
/*   Updated: 2022/09/29 19:08:31 by twinters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

// rajouter de quoi free ft_split

void	ft_str_free(char **str)
{
	int i;

	while(str[i])
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

void	fst_command(t_data pipex)
{
	char	**cmd_args;

	pipex.pid1 = fork();
	if (pipex.pid1 == 0)
	{
		dup2(pipex.pipe[1], 1);
		dup2(pipex.infile, 0);
		cmd_args = ft_split(pipex.args[2], ' ');
		execve(cmd_args[0], cmd_args, pipex.envp);
		ft_str_free(cmd_args);
		exit(EXIT_SUCCESS);
	}
	waitpid(pipex.pid1, NULL, 0);
}
void	snd_command(t_data pipex)
{
	char	**cmd_args;

	pipex.pid2 = fork();
	if (pipex.pid1 == 0)
	{
		dup2(pipex.outfile, 1);
		dup2(pipex.pipe[0], 0);
		cmd_args = ft_split(pipex.args[3], ' ');
		execve(cmd_args[0], cmd_args, pipex.envp);
		ft_str_free(cmd_args);
		exit(EXIT_SUCCESS);
	}
	waitpid(pipex.pid2, NULL, 0);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_data	pipex;

	if (argc != 5)
		error_msg("Error\n");
	pipex.args = argv;
	pipex.envp = envp;
	pipex.infile = open(argv[1], O_RDONLY);
	pipex.outfile = open(argv[4], O_WRONLY);
	pipe(pipex.pipe);
	if (pipex.infile < 0 || pipex.outfile < 0)
		error_msg("Error\n");
	fst_command(pipex);
	snd_command(pipex);
	close(pipex.infile);
	close(pipex.outfile);

	return (0);
}