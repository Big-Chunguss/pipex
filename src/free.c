/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaroux <agaroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 16:16:42 by agaroux           #+#    #+#             */
/*   Updated: 2025/04/29 13:33:40 by agaroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	free_tab(char **tab)
{
	int	i;

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
		free(args->path);
	}
	free(args);
}
