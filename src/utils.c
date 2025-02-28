/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afodil-c <afodil-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 15:34:07 by afodil-c          #+#    #+#             */
/*   Updated: 2025/02/28 23:01:18 by afodil-c         ###   ########.fr       */
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
	int		i;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
			return (ft_split(envp[i] + 5, ':'));
		i++;
	}
	return 0;
}

void	ft_exe(char *cmd, char **envp)
{
	int		i;
	char	**command;
	char	**path;
	char	*full_path;

	command = ft_split(cmd, ' ');
	path = ft_find_path(envp);
	if (!path)
		ft_error("Error: no PATH");
	i = 0;
	if(!envp)
		return;
	while (path[i])
	{
		full_path = ft_join_path(path[i], '/', command[0]);
		if (access(full_path, F_OK) == 0)
			execve(full_path, command, envp);
		free(full_path);
		i++;
	}
	ft_free_array(command);
	ft_free_array(path);
	ft_error("Error: command not found");
}

char	*ft_join_path(char const *dir, char sep, char const *cmd)
{
	char	*path;
	size_t	i;
	size_t	j;
	size_t	len_dir;
	size_t	len_cmd;

	i = 0;
	j = 0;
	if (!dir || !cmd)
		return 0;
	len_dir = ft_strlen(dir);
	len_cmd = ft_strlen(cmd);
	path = (char *)malloc(sizeof(char) * (len_dir + len_cmd + 2));
	if (!path)
		return 0;

	while (j < len_dir)
	{
		path[i] = dir[j];
		i++;
		j++;
	}
	path[i] = sep;
	i++;
	j = 0;
	while (j < len_cmd)
	{
		path[i] = cmd[j];
		i++;
		j++;
	}
	path[i] = '\0';
	return (path);
}

void	ft_free_array(char **array)
{
	int	i;

	if (!array)
		return;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
