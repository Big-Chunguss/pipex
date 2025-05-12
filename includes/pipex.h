/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaroux <agaroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:43:00 by agaroux           #+#    #+#             */
/*   Updated: 2025/05/12 14:20:55 by agaroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../lib/ftprintf/ft_printf.h"
# include "../lib/libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <time.h>
# include <unistd.h>

typedef struct s_path
{
	char	*cmd;
	char	**paths;
	char	*full_path;
	char	**split_cmd;
	char	*tmp;
}			t_path;

typedef struct s_args
{
	int		ac;
	pid_t	pid1;
	pid_t	pid2;
	char	**av;
	char	**env;
	t_path	*path;
}			t_args;

void		free_tab(char **tab);
int			parent(char **av, int *fd, char **env, t_args *args);
int			child(char **av, int *fd, char **env, t_args *args);
int			main(int argc, char **argv, char **env);
void		print_tab(char **map);
char		*get_cmd_path(char *cmd, char **env, t_args *args);
void		free_struct(t_args *args);
t_args		*init_struct(int argc, char **argv, char **env);
void		shorten_main(t_args *args, int *fd);
int			error_open(char **av, int *fd, int i);
int			total_access(char *str);

#endif
