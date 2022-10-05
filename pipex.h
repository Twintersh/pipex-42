/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twinters <twinters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:06:03 by twinters          #+#    #+#             */
/*   Updated: 2022/10/05 12:42:46 by twinters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <sys/types.h>
# include <sys/wait.h>

# define PIPE_IN 1
# define PIPE_OUT 0
# define CHILD 0

typedef struct s_commands
{
	char	**cmd1;
	char	**cmd2;
}t_commands;

typedef struct s_data
{
	int					infile;
	int					outfile;
	int					pipe[2];
	char				**args;
	char				**envp;
	struct s_commands	*c;	
}t_data;

// main.c

//static void ft_close(t_data *pipex);
//static void split_cmds(t_data *pipex);
void	check_errors(t_data *pipex, int pipe_value);
void	msg_exit(char *str);
int		main(int argc, char **argv, char **envp);

// pipex.c

t_data	*init_pipex(char **argv, char **envp);
void	ft_str_free(char **str);
void	error_msg(char *str, t_data *pipex, int exit);
void	fst_command(t_data *pipex, char *cmd_p);
void	snd_command(t_data *pipex, char *cmd_p);

// access.c

// static char	*get_path(char **envp);
// static char	*add_path(char *path, char *cmd);
char	*get_cmd_path(char *cmd, char **envp);

#endif
