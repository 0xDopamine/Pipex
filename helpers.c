/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 21:37:05 by mbaioumy          #+#    #+#             */
/*   Updated: 2022/02/28 21:45:41 by mbaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strcmp(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i] && i < n - 1)
		i++;
	return (s1[i] - s2[i]);
}

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

char	*cat(char *dest, char const *s, int pos)
{
	int	i;

	i = 0;
	while (s[i])
	{
		dest[pos] = s[i];
		pos++;
		i++;
	}
	dest[pos] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tab;
	size_t	total;
	int		i;
	int		j;

	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	total = ft_strlen(s1) + ft_strlen(s2) + 1;
	i = 0;
	tab = (char *)malloc(sizeof(char) * total + 1);
	if (!tab)
		return (NULL);
	tab = cat(tab, s1, 0);
	tab = cat(tab, s2, ft_strlen(s1));
	return (tab);
}
