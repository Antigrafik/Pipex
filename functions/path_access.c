/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_access.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmurgia- <mmurgia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 12:20:24 by mmurgia-          #+#    #+#             */
/*   Updated: 2022/10/07 11:09:39 by mmurgia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	**get_paths(char **env)
{
	int		i;
	char	**paths;

	i = 0;
	paths = NULL;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			paths = ft_split(env[i] + 5, ':');
		i++;
	}
	return (paths);
}

char	**get_cmd(char **argv)
{
	char	**cmd;

	cmd = ft_split(argv[0], ' ');
	return (cmd);
}

char	*path_cmd(char **env, char **argv)
{
	char	**paths;
	char	*temp;
	char	*path;
	char	**cmd;
	int		i;

	cmd = get_cmd(argv);
	paths = get_paths(env);
	i = 0;
	while (paths[i])
	{
		paths[i] = ft_strjoin(paths[i], "/");
		paths[i] = ft_strjoin(paths[i], cmd[0]);
		temp = paths[i];
		if (access(temp, F_OK) == 0)
			path = temp;
		else
			free(temp);
		i++;
	}
	return (path);
}
