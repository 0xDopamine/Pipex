/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 21:45:08 by mbaioumy          #+#    #+#             */
/*   Updated: 2022/02/28 21:46:03 by mbaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	freethis(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	wdlen(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && ft_strncmp((char *)&s[i], &c, 1))
		i++;
	return (i);
}

int	wdcount(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count += 1;
		i++;
	}
	return (count);
}

char	**splitting(char const *s, char c, int len, char **str)
{
	int		k;
	int		j;
	int		i;

	i = 0;
	j = -1;
	while (s[i])
	{
		while (s[i] && !ft_strncmp((char *)&s[i], &c, 1))
			i++;
		if (!s[i])
			break ;
		len = wdlen(s + i, c);
		str[++j] = (char *)ft_calloc(len + 1, sizeof(char));
		if (!str[j])
		{
			freethis(str);
			return (NULL);
		}
		k = -1;
		while (++k < len)
			str[j][k] = s[i++];
	}
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	char	**str;

	if (!s)
		return (NULL);
	str = (char **)ft_calloc((wdcount(s, c) + 1), sizeof(char *));
	if (!str)
		return (NULL);
	split = splitting(s, c, 0, str);
	return (split);
}
