/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twinters <twinters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:06:03 by twinters          #+#    #+#             */
/*   Updated: 2022/10/02 12:37:30 by twinters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "lib-twinters/libft.h"
# include <sys/types.h>
# include <sys/wait.h>
# include <stdio.h>

# define PIPE_IN 1
# define PIPE_OUT 0
# define CHILD 0

typedef struct s_data
{
	int		infile;
	int		outfile;
	int		pipe[2];
	pid_t	pid1;
	pid_t	pid2;
	char	**args;
	char	**envp;
}t_data;

// main.c

int		main(int argc, char **argv, char **envp);

// pipex.c

t_data	*init_pipex(char **argv, char **envp);
void	ft_str_free(char **str);
void	error_msg(char *str);
void	fst_command(t_data *pipex);
void	snd_command(t_data *pipex);

// access.c

// static char	*get_path(char **envp);
// static char	*add_path(char *path, char *cmd);
char	*get_cmd_path(char *cmd, char **envp);

#endif