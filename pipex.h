/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmurgia- <mmurgia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:20:09 by mmurgia-          #+#    #+#             */
/*   Updated: 2022/10/07 11:17:01 by mmurgia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>
# include <string.h>
# include <errno.h>

typedef struct s_data
{
	int		fd[2];
	char	*path;
	char	**cmd;
	pid_t	pid;
}		t_data;

/*  pipex.c    */
void		ft_child(char **argv, char **env, t_data param);
void		ft_father(char **argv, char **env, t_data param);

/*  path_access.c    */
char		**get_paths(char **env);
char		**get_cmd(char **argv);
char		*path_cmd(char **env, char **argv);

/*  utils.c    */
void		*ft_calloc(size_t count, size_t size);
void		ft_bzero(void *s, size_t n);
int			ft_strchar(char *str, char c);
size_t		ft_strlen(const char *str);

/*  ft_strjoin.c    */
char		*ft_strjoin(char const *s1, char const *s2);

/*  ft_split.c   */
char		**ft_split(char const *s, char c);

/*  ft_strncmp.c   */
int			ft_strncmp(const char *s1, const char *s2, size_t n);

/*  ft_strdup.c    */
char		*ft_strdup(const char *s);

#endif