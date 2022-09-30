/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twinters <twinters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 11:24:55 by twinters          #+#    #+#             */
/*   Updated: 2022/09/30 16:37:50 by twinters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_data	*pipex;

	if (argc != 5)
		error_msg("Invalid number of arguments\n");
	pipex = init_pipex(argv, envp);
	pipex->infile = open(argv[1], O_RDONLY);
	pipex->outfile = open(argv[4], O_WRONLY);
	pipe(pipex->pipe);
	if (pipex->infile < 0 || pipex->outfile < 0)
		error_msg("File descriptor error\n");
	fst_command(pipex);
	snd_command(pipex);
	close(pipex->pipe[0]);
	close(pipex->pipe[1]);
	close(pipex->infile);
	close(pipex->outfile);
	free(pipex);
	return (0);
}
