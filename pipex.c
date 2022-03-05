/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 01:13:26 by mbaioumy          #+#    #+#             */
/*   Updated: 2022/03/05 18:09:39 by mbaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/wait.h>
#include "pipex.h"

char	*findthewae(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_strcmp(str[i], "PATH=", 5) == 0)
			return (str[i] + 5);
		i++;
	}
	return (0);
}

void	execute(char **env, char *cmd)
{
	char	*path;
	char	**cmdpaths;
	int		i;
	char	*arg;
	char	**cmda;

	i = -1;
	path = findthewae(env);
	if (!path)
		return (perror("PATH_Error"));
	cmdpaths = ft_split(path, ':');
	cmda = ft_split(cmd, ' ');
	while (cmdpaths[++i])
	{
		arg = ft_strjoin(cmdpaths[i], "/");
		arg = ft_strjoin(arg, cmda[0]);
		if (access(arg, F_OK) == 0)
			if (!execve(arg, cmda, env))
				perror("Exec Error");
	}
	perror(cmd);
}

void	child_process(int *fd, char **env, char **argv, int id)
{
	int	file1;
	int	file2;

	file1 = open(argv[1], O_RDONLY);
	file2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0777);
	if (file1 < 0 || file2 < 0)
		exit (-1);
	if (id)
	{
		dup2(fd[1], STDOUT_FILENO);
		dup2(file1, 0);
		close(fd[0]);
		close(fd[1]);
		execute(env, argv[2]);
	}
	else
	{
		dup2(fd[0], STDIN_FILENO);
		dup2(file2, 1);
		close(fd[0]);
		close(fd[1]);
		execute(env, argv[3]);
	}
}

void	pipex(char **argv, char **env)
{
	int	fd[2];
	int	pid1;
	int	pid2;

	if (pipe(fd) < 0)
		perror("Pipe Error");
	pid1 = fork();
	if (pid1 == -1)
		perror("First Fork Error");
	if (pid1 == 0)
		child_process(fd, env, argv, 1);
	pid2 = fork();
	if (pid2 == -1)
		perror("Second Fork Error");
	if (pid2 == 0)
		child_process(fd, env, argv, 0);
	close(fd[0]);
	close(fd[1]);
	wait(0);
}

int	main(int argc, char **argv, char **env)
{
	argc = 0;
	pipex(argv, env);
	return (0);
}
