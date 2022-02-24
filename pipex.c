/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 01:13:26 by mbaioumy          #+#    #+#             */
/*   Updated: 2022/02/24 03:18:08 by mbaioumy         ###   ########.fr       */
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

void	execute(char **env, char *cmd, char *cmdArg)
{
	char	*path;
	char	**cmdPaths;
	int		i;
	char	*arg;

	i = -1;
	path = findthewae(env);
	cmdPaths = ft_split(path, ':');
	while (cmdPaths[++i])
	{
		//printf("%s\n", cmdPaths[i]);
		//printf("%s", cmd);
		arg = ft_strjoin(cmdPaths[i], "/");
		arg = ft_strjoin(arg, cmd);
		//printf("%s\n", arg);
		execve(arg, &cmdArg, env);
	}
}

void	pipex(int file1, int file2, char *cmd1, char *cmd2, char **env)
{
	int fd[2];
	int pid1;
	int cid1;
	int	p;

	//p = pipe(fd);
	//if (p < 0)
		//return ;
	pid1 = fork();
	//cid1 = getpid();
	//if (pid1 == -1)
	//	return ;
	//printf("pid1 %d/n", pid1);
	if (pid1 == 0)
	{
		//printf("im here");
		//dup2(fd[1], STDOUT_FILENO);
		//close(file1);
		//close(fd[0]);
		//close(fd[1]);
		execute(env, cmd1, cmd2);
	}

	// int pid2 = fork();
	// if (pid2 < 0)
	// 	return ;
	// if (pid2 == 0)
	// {
	// 	dup2(fd[0], STDIN_FILENO);
	// 	close(fd[0]);
	// 	close(fd[1]);
	// 	execute(env, cmd2);
	// }
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	//waitpid(pid2, NULL, 0);
}

int main(int argc, char **argv, char **env)
{
	// int file1, file2;

	// file1 = open(argv[1], O_RDONLY);
	// file2 = open(argv[4], O_CREAT | O_RDWR, 0777);
	// if (file1 < 0 || file2 < 0)
	// 	return (-1);
	pipex(42, 42, argv[1], argv[2], env);
	return (0);
}
