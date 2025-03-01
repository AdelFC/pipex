/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afodil-c <afodil-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 15:32:15 by afodil-c          #+#    #+#             */
/*   Updated: 2025/03/01 23:39:38 by afodil-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_command1(int fd[2], char **argv, char **envp)
{
	int	f_in;

	f_in = open(argv[1], O_RDONLY);
	if (f_in < 0)
		ft_error("Error: input file");
	if (dup2(f_in, STDIN_FILENO) == -1 || dup2(fd[1], STDOUT_FILENO) == -1)
		ft_error("Error: dup2 failed");
	close(fd[0]);
	close(fd[1]);
	close(f_in);
	ft_exe(argv[2], envp);
}

void	ft_command2(int fd[2], char **argv, char **envp)
{
	int	f_out;

	f_out = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (f_out < 0)
		ft_error("Error: output file");
	if (dup2(fd[0], STDIN_FILENO) == -1 || dup2(f_out, STDOUT_FILENO) == -1)
		ft_error("Error: dup2 failed");
	close(fd[0]);
	close(fd[1]);
	close(f_out);
	ft_exe(argv[3], envp);
}

int	ft_process1(int fd[2], char **argv, char **envp)
{
	int	pid;

	pid = fork();
	if (pid == -1)
		ft_error("Error: fork pid1");
	else if (pid == 0)
	{
		close(fd[0]);
		ft_command1(fd, argv, envp);
		close(fd[1]);
		exit(EXIT_FAILURE);
	}
	return (pid);
}

int	ft_process2(int fd[2], char **argv, char **envp)
{
	int	pid;

	pid = fork();
	if (pid == -1)
		ft_error("Error: fork pid2");
	else if (pid == 0)
	{
		close(fd[1]);
		ft_command2(fd, argv, envp);
		close(fd[0]);
		exit(EXIT_FAILURE);
	}
	return (pid);
}

int	main(int argc, char **argv, char **envp)
{
	int	fd[2];
	int	pid1;
	int	pid2;

	if (argc != 5)
		ft_error("Error: invalid number of arguments");
	if (pipe(fd) == -1)
		ft_error("Error: pipe failed");
	pid1 = ft_process1(fd, argv, envp);
	pid2 = ft_process2(fd, argv, envp);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
