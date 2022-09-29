/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twinters <twinters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:06:03 by twinters          #+#    #+#             */
/*   Updated: 2022/09/29 17:53:22 by twinters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "lib-twinters/libft.h"
# include <sys/types.h>
# include <sys/wait.h>
# include <stdio.h>

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

int	main(int argc, char **argv, char **envp);

#endif