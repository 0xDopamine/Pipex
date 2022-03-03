/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 21:37:56 by mbaioumy          #+#    #+#             */
/*   Updated: 2022/02/28 21:46:48 by mbaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define LIBFT_H

# include<stdlib.h>
# include<string.h>
# include<stdio.h>

int		ft_strcmp(char *s1, char *s2, int n);
void	first_child_process(int *fd, char **argv, char **env);
void	second_child_process(int *fd, char **argv, char **env);
void	pipex(char **argv, char **env);
char	*findthewae(char **str);
char	*cat(char *dest, char const *s, int pos);
char	*ft_strjoin(char const *s1, char const *s2);
void	freethis(char **str);
int		wdlen(char const *s, char c);
int		wdcount(char const *s, char c);
char	**splitting(char const *s, char c, int len, char **str);
char	**ft_split(char const *s, char c);

#endif