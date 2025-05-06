/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaroux <agaroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 16:16:42 by agaroux           #+#    #+#             */
/*   Updated: 2025/05/06 11:19:29 by agaroux          ###   ########.fr       */
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
