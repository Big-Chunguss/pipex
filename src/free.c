/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaroux <agaroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 16:16:42 by agaroux           #+#    #+#             */
/*   Updated: 2025/05/12 14:27:27 by agaroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	free_tab(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

void	free_struct(t_args *args)
{
	if (!args)
		return ;
	if (args->path)
	{
		if (args->path->cmd)
			free(args->path->cmd);
		if (args->path->paths)
			free_tab(args->path->paths);
		if (args->path->split_cmd)
			free_tab(args->path->split_cmd);
		if (args->path->cmd)
			free(args->path->cmd);
		free(args->path);
	}
	free(args);
}

int	error_open(char **av, int *fd, int i)
{
	close(fd[0]);
	close(fd[1]);
	if (i == 4)
		if (total_access(av[1]))
			return (127);
	if (total_access(av[i]))
		return (127);
	return (0);
}

int	total_access(char *str)
{
	if (access(str, F_OK))
	{
		ft_printf("no such file or directory: %s\n", str);
		return (1);
	}
	else if (access(str, X_OK) || access(str, W_OK) || access(str, R_OK))
	{
		ft_printf("%s: Permission denied\n", str);
		return (1);
	}
	return (0);
}

t_args	*init_struct(int argc, char **argv, char **env)
{
	t_args	*args;
	t_path	*path;

	args = malloc(sizeof(t_args));
	if (!args)
		return (NULL);
	path = malloc(sizeof(t_path));
	if (!path)
		return (NULL);
	args->path = path;
	args->ac = argc;
	args->av = argv;
	args->env = env;
	args->path->cmd = NULL;
	args->path->full_path = NULL;
	args->path->paths = NULL;
	args->path->split_cmd = NULL;
	return (args);
}
