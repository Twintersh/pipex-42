/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twinters <twinters@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 21:48:24 by twinters          #+#    #+#             */
/*   Updated: 2022/10/02 12:38:49 by twinters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static char	*get_path(char **envp)
{
	int	i;

	i = 0;
	while (ft_strncmp("PATH=", envp[i], 4))
		i++;
	return (envp[i]);
}

static char	*add_path(char *path, char *cmd)
{
	char	*cmd_p;
	char	*buff;

	if (*cmd == '/')
		error_msg("Bad command\n");
	buff = ft_strjoin("/", cmd);
	cmd_p = ft_strjoin(path, buff);
	free(buff);
	return (cmd_p);
}

char	*get_cmd_path(char *cmd, char **envp)
{
	char	**path;
	char	*cmd_p;
	int		i;

	i = 0;
	if (!access(cmd, F_OK))
		return (ft_strjoin("", cmd));
	path = ft_split(get_path(envp) + 5, ':');
	cmd_p = add_path(path[i], cmd);
	while (access(cmd_p, F_OK))
	{
		i++;
		free(cmd_p);
		if (path[i])
			cmd_p = add_path(path[i], cmd);
		else
		{
			error_msg("Bad command\n");
			ft_str_free(path);
		}
	}
	ft_str_free(path);
	return (cmd_p);
}
