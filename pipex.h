/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 21:37:56 by mbaioumy          #+#    #+#             */
/*   Updated: 2022/03/05 15:51:38 by mbaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define LIBFT_H

# include<stdlib.h>
# include<string.h>
# include<stdio.h>

int		ft_strcmp(char *s1, char *s2, int n);
void	first_child_process(int *fd, int file, char **env, char *argv);
void	second_child_process(int *fd, int file, char **env, char *argv);
void	pipex(char **argv, char **env);
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

#endif