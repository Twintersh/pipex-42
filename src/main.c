/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twinters <twinters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 11:24:55 by twinters          #+#    #+#             */
/*   Updated: 2022/10/04 13:31:38 by twinters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_data	*pipex;
	int		pipe_value;

	if (argc != 5)
		error_msg("Invalid number of arguments\n", NULL);
	pipex = init_pipex(argv, envp);
	pipex->infile = open(argv[1], O_RDONLY);
	pipex->outfile = open(argv[4], O_TRUNC ^ O_CREAT ^ O_WRONLY, 0664);
	if (pipex->infile < 0)
		ft_printf("%s : bad file descriptor\n", argv[1]);
	if (pipex->outfile < 0)
		error_msg("File descriptor outfile error\n", pipex);
	pipe_value = pipe(pipex->pipe);
	if (pipe_value < 0)
		error_msg("Pipe error\n", pipex);
	if (pipex->infile >= 0)
		fst_command(pipex);
	snd_command(pipex);
	close(pipex->pipe[0]);
	close(pipex->pipe[1]);
	close(pipex->infile);
	close(pipex->outfile);
	free(pipex);
	return (0);
}
