/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 01:13:26 by mbaioumy          #+#    #+#             */
/*   Updated: 2022/04/06 22:35:50 by mbaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute(char **env, char *cmd)
{
	t_data2	data;

	data.i = -1;
	data.path = findthewae(env);
	if (!data.path)
		return (perror("PATH_Error"));
	data.cmdpaths = ft_split(data.path, ':');
	data.cmda = ft_split(cmd, ' ');
	if (cmd[0] == '/')
	{
		if (access(cmd, X_OK) == 0)
			if (!execve(cmd, data.cmda, env))
				write(2, "Execution Error", 13);
	}
	while (data.cmdpaths[++data.i])
	{
		data.arg = ft_strjoin(data.cmdpaths[data.i], "/");
		data.arg = ft_strjoin(data.arg, data.cmda[0]);
		if (access(data.arg, X_OK) == 0)
			if (!execve(data.arg, data.cmda, env))
				write(2, "Execution Error", 13);
	}
	error_handling(cmd);
	exit(1);
}

void	child_process(char **env, char **argv, t_data data)
{
	if (data.index == 2)
	{
		dup2(data.fd[1], 1);
		dup2(data.file1, 0);
	}
	else if (data.index == data.argc - 2)
		dup2(data.file2, 1);
	else
		dup2(data.fd[1], 1);
	close(data.fd[0]);
	close(data.fd[1]);
	close(data.file1);
	close(data.file2);
	execute(env, argv[data.index]);
}

void	pipe_n_fork(t_data data, char **env, char **argv)
{
	if (pipe(data.fd) < 0)
		perror("Pipe Error");
	data.pid1 = fork();
	if (data.pid1 == -1)
		perror("Fork Error");
	if (data.pid1 == 0)
		child_process(env, argv, data);
	dup2(data.fd[0], 0);
	close(data.fd[0]);
	close(data.fd[1]);
}

void	pipex(char **argv, char **env, int argc)
{
	t_data	data;

	data.file1 = open(argv[1], O_RDONLY);
	data.file2 = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	data.index = 1;
	data.argc = argc;
	while (++data.index < argc - 1)
		pipe_n_fork(data, env, argv);
	while (wait(NULL) != -1)
		;
}
