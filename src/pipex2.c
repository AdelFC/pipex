/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afodil-c <afodil-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 15:34:07 by afodil-c          #+#    #+#             */
/*   Updated: 2025/03/13 18:03:36 by afodil-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

char	**ft_find_path(char **envp)
{
	int	i;

	i = 0;
	if (!envp)
		return (NULL);
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
			return (ft_split(envp[i] + 5, ':'));
		i++;
	}
	return (0);
}

void	ft_exe(char *cmd, char **envp)
{
	char	**command;
	char	**path;

	command = ft_split(cmd, ' ');
	if (!command)
		ft_error("Error: memory allocation failed");
	path = ft_find_path(envp);
	if (!path)
	{
		execve(cmd, command, envp);
		ft_free_array(command);
		ft_error("Error: command not found");
	}
	ft_execve_paths(command, path, envp, cmd);
}

void	ft_execve_paths(char **command, char **path, char **envp, char *cmd)
{
	int		i;
	char	*full_path;

	i = 0;
	if (!envp)
		return ;
	while (path[i])
	{
		full_path = ft_join_path(path[i], '/', command[0]);
		if (!full_path)
		{
			ft_free_array(command);
			ft_free_array(path);
			ft_error("Error: memory allocation failed");
		}
		if (access(full_path, F_OK) == 0)
			execve(full_path, command, envp);
		free(full_path);
		i++;
	}
	execve(cmd, command, envp);
	ft_free_array(command);
	ft_free_array(path);
	ft_error("Error: command not found");
}

char	*ft_join_path(char const *dir, char sep, char const *cmd)
{
	char	*path;
	size_t	len_dir;
	size_t	len_cmd;

	if (!dir || !cmd)
		return (0);
	len_dir = ft_strlen(dir);
	len_cmd = ft_strlen(cmd);
	path = (char *)malloc(sizeof(char) * (len_dir + len_cmd + 2));
	if (!path)
		return (0);
	ft_strlcpy(path, dir, len_dir + 1);
	path[len_dir] = sep;
	ft_strlcpy(path + len_dir + 1, cmd, len_cmd + 1);
	return (path);
}
