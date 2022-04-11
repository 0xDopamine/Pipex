/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 21:37:56 by mbaioumy          #+#    #+#             */
/*   Updated: 2022/04/06 22:33:31 by mbaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define LIBFT_H

# include<stdlib.h>
# include<string.h>
# include<stdio.h>
# include<unistd.h>
# include<fcntl.h>
# include<errno.h>
# include<sys/types.h>
# include<sys/wait.h>

typedef struct s_data
{
	int	fd[2];
	int	file1;
	int	file2;
	int	index;
	int	pid1;
	int	argc;
}	t_data;

typedef struct s_data2
{
	char	*path;
	char	**cmdpaths;
	int		i;
	char	*arg;
	char	**cmda;
}	t_data2;

size_t	ft_strlen(char *str);
void	first_child_process(int *fd, int file, char **env, char *argv);
void	second_child_process(int *fd, int file, char **env, char *argv);
void	pipex(char **argv, char **env, int argc);
char	*findthewae(char **str);
char	*cat(char *dest, char const *s, int pos);
char	*ft_strjoin(char *s1, char *s2);
void	freethis(char **str);
int		wdlen(char const *s, char c);
int		wdcount(char const *s, char c);
char	**splitting(char const *s, char c, int len, char **str);
char	**ft_split(char const *s, char c);
int		ft_strncmp(char *s1, char *s2, unsigned int n);
void	*ft_calloc(size_t count, size_t size);
int		file_protection(t_data data, char **argv, int argc);
void	error_handling(char *cmd);

#endif