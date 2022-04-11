/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 15:24:25 by mbaioumy          #+#    #+#             */
/*   Updated: 2022/04/06 22:33:20 by mbaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_data	data;

	data.file1 = open(argv[1], O_RDONLY);
	data.file2 = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (file_protection(data, argv, argc))
	{
		if (argc == 5)
			pipex(argv, env, argc);
		else
			perror("Args Error: More or less 5 arguments");
	}
	return (0);
}
