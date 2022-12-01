/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmurgia- <mmurgia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:20:12 by mmurgia-          #+#    #+#             */
/*   Updated: 2022/12/01 09:38:28 by mmurgia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_child(char **argv, char **env, t_data param)
{
	int		infile;

	close(param.fd[0]);
	infile = open(argv[1], O_RDONLY);
	if (infile < 0)
	{
		perror("Error");
		printf("Please, enter a valid file.\n");
		exit (0);
	}
	dup2(param.fd[1], STDOUT_FILENO);
	dup2(infile, STDIN_FILENO);
	close(param.fd[1]);
	execve(param.path, param.cmd, env);
}

void	ft_father(char **argv, char **env, t_data param)
{
	int		outfile;

	close(param.fd[1]);
	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (outfile == -1)
		perror("Out Error");
	dup2(outfile, STDOUT_FILENO);
	dup2(param.fd[0], STDIN_FILENO);
	close(param.fd[0]);
	execve(param.path, param.cmd, env);
}

int	main(int argc, char **argv, char **env)
{
	t_data	param;

	pipe(param.fd);
	param.pid = fork();
	if (param.pid == -1)
		perror("Error");
	if (argc < 5)
		printf("Error: not enough arguments\n");
	else if (argc > 5)
		printf("Error: too many arguments\n");
	else
	{
		param.path = path_cmd(env, &argv[2]);
		param.cmd = get_cmd(&argv[2]);
		if (param.pid == 0)
			ft_child(argv, env, param);
		else
		{
			param.path = path_cmd(env, &argv[3]);
			param.cmd = get_cmd(&argv[3]);
			waitpid(param.pid, NULL, 0);
			ft_father(argv, env, param);
		}
	}
	return (1);
}
