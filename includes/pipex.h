/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afodil-c <afodil-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:59:31 by afodil-c          #+#    #+#             */
/*   Updated: 2025/03/01 12:34:43 by afodil-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../lib/ftprintf/ft_printf.h"
# include "../lib/get_next_line/get_next_line.h"
# include "../lib/libft/libft.h"
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

void	ft_error(char *str);
char	**ft_find_path(char **envp);
void	ft_exe(char *cmd, char **envp);
char	*ft_join_path(char const *dir, char sep, char const *cmd);
void	ft_free_array(char **array);

void	ft_command1(int fd[2], char **argv, char **envp);
void	ft_command2(int fd[2], char **argv, char **envp);
int		ft_process1(int fd[2], char **argv, char **envp);
int		ft_process2(int fd[2], char **argv, char **envp);
int		main(int argc, char **argv, char **envp);

#endif
