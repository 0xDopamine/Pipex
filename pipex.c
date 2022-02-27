/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 01:13:26 by mbaioumy          #+#    #+#             */
/*   Updated: 2022/02/27 19:41:25 by mbaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/wait.h>
#include "libft.h"

int     ft_strcmp(char *s1, char *s2, int n)
{
    int i = 0;
    while(s1[i] == s2[i] && s1[i] && s2[i] && i < n - 1)
        i++;
    return (s1[i] - s2[i]);
}

char	*findthewae(char **str)
{
    int i = 0;
    while(str[i])
    {
        if(ft_strcmp(str[i], "PATH=", 5) == 0)
            return (str[i] + 5);
        i++;
    }
    return ("zbi");
}

void	execute(char **env, char *cmd)
{
	char	*path;
	char	**cmdPaths;
	int		i;
	char	*arg;
	char	**cmda;

	i = -1;
	path = findthewae(env);
	cmdPaths = ft_split(path, ':');
	cmda = ft_split(cmd, ' ');
	while (cmdPaths[++i])
	{
		arg = ft_strjoin(cmdPaths[i], "/");
		arg = ft_strjoin(arg, cmda[0]);
		execve(arg, cmda, env);
	}
}

void	pipex(int file1, int file2, char *cmd1, char *cmd2, char **env)
{
	int fd[2];
	int pid1;

	if (pipe(fd) < 0)
		return ;
	pid1 = fork();
	if (pid1 == -1)
		return ;
	if (pid1 == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		execute(env, cmd1);
	}
	close(file1);
	int pid2 = fork();
	if (pid2 < 0)
		return ;
	if (pid2 == 0)
	{
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		execute(env, cmd2);
	}
	close(file2);
	close(fd[0]);
	close(fd[1]);
	wait(0);
}

int main(int argc, char **argv, char **env)
{
	int file1, file2;

	file1 = open(argv[1], O_RDONLY);
	file2 = open(argv[4], O_CREAT | O_RDWR, 0777);
	if (file1 < 0 || file2 < 0)
		return (-1);
	pipex(file1, file2, argv[2], argv[3], env);
	//system("a out leaks");
	return (0);
}