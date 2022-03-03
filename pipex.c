/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 01:13:26 by mbaioumy          #+#    #+#             */
/*   Updated: 2022/03/02 13:12:28 by mbaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/wait.h>
#include "pipex.h"

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
			execve(arg, cmda, env);
	}
	perror("./pipex");
}

void	first_child_process(int *fd, char **argv, char **env)
{
	dup2(fd[1], STDOUT_FILENO);
	dup2(argv[1], 0);
	close(fd[0]);
	close(fd[1]);
	execute(env, argv[2]);
}

void	second_child_process(int *fd, char **argv, char **env)
{
	dup2(fd[0], STDIN_FILENO);
	dup2(argv[4], 1);
	close(fd[0]);
	close(fd[1]);
	execute(env, argv[3]);
}

void	pipex(char **argv, char **env)
{
	int	fd[2];
	int	pid1;
	int	pid2;
	int	file1;
	int	file2;

	file1 = open(argv[1], O_RDONLY);
	file2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0777);
	if (file1 < 0 || file2 < 0)
		return (-1);
	if (pipe(fd) < 0)
		return ;
	pid1 = fork();
	if (pid1 == -1)
		return ;
	if (pid1 == 0)
		first_child_process(fd, argv, env);
	pid2 = fork();
	if (pid2 < 0)
		return ;
	if (pid2 == 0)
		second_child_process(fd, argv, env);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, NULL);
	waitpid(pid2, NULL, NULL);
}

int	main(int argc, char **argv, char **env)
{
	pipex(argv, env);
	return (0);
}
