/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 21:37:05 by mbaioumy          #+#    #+#             */
/*   Updated: 2022/03/23 15:52:18 by mbaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && i < n - 1)
	{
		if (s1[i] == s2[i])
			i++;
		else
			break ;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char	*findthewae(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_strncmp(str[i], "PATH=", 5) == 0)
			return (str[i] + 5);
		i++;
	}
	return (0);
}

void	file_protection(t_data data, char **argv, int argc)
{
	if (data.file1 < 0)
	{	
		write(2, "zsh: no such file or directory: ", 32);
		write(2, argv[1], ft_strlen(argv[1]));
		write(2, "\n", 1);
	}
	else if (data.file2 < 0)
	{
		write(2, "zsh: no such file or directory: ", 32);
		write(2, argv[argc - 1], ft_strlen(argv[argc - 1]));
		write(2, "\n", 1);
	}
}

void	error_handling(char *cmd)
{
	write(2, "zsh: command not found: ", 24);
	write(2, cmd, ft_strlen(cmd) + 1);
	write(2, "\n", 1);
}
