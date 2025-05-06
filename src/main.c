/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaroux <agaroux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 16:16:42 by agaroux           #+#    #+#             */
/*   Updated: 2025/05/06 13:03:47 by agaroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	parent(char **av, int *fd, char **env, t_args *args)
{
	int	outfile;

	outfile = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile == -1)
		return (127);
	args->path->split_cmd = ft_split(av[3], ' ');
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	dup2(outfile, STDOUT_FILENO);
	close(outfile);
	if (!args->path->split_cmd[0])
	{
		free_tab(args->path->split_cmd);
		args->path->split_cmd = ft_split("cat", ' ');
	}
	args->path->cmd = get_cmd_path(args->path->split_cmd[0], env, args);
	if (!args->path->cmd)
		return (write(2, "command not found parent\n", 24), 127);
	if (execve(args->path->cmd, args->path->split_cmd, env) == -1)
		return (perror("execve"), 127);
	return (0);
}

int	child(char **av, int *fd, char **env, t_args *args)
{
	int	infile;

	infile = open(av[1], O_RDWR, 0644);
	if (infile == -1)
		return (127);
	args->path->split_cmd = ft_split(av[2], ' ');
	dup2(infile, STDIN_FILENO);
	close(infile);
	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	if (!args->path->split_cmd[0])
	{
		free_tab(args->path->split_cmd);
		args->path->split_cmd = ft_split("cat", ' ');
	}
	args->path->cmd = get_cmd_path(args->path->split_cmd[0], env, args);
	if (!args->path->cmd)
		return (write(2, "command not found child\n", 23), 127);
	if (execve(args->path->cmd, args->path->split_cmd, env) == -1)
		return (perror("execve"), 127);
	return (0);
}

char	*get_cmd_path(char *cmd, char **env, t_args *args)
{
	int	i;

	i = -1;
	if (access(cmd, X_OK) == 0)
		return (cmd);
	while (env[++i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			args->path->paths = ft_split(env[i] + 5, ':');
	}
	if (!args->path->paths)
		return (NULL);
	i = -1;
	while (args->path->paths[++i])
	{
		args->path->tmp = ft_strjoin(args->path->paths[i], "/");
		args->path->full_path = ft_strjoin(args->path->tmp, cmd);
		free(args->path->tmp);
		if (access(args->path->full_path, X_OK) == 0)
			return (args->path->full_path);
		free(args->path->full_path);
	}
	return (NULL);
}

void	shorten_main(t_args *args, int *fd)
{
	close(fd[0]);
	close(fd[1]);
	while (1)
	{
		if (waitpid(args->pid1, NULL, WNOHANG) != 0 && waitpid(args->pid2, NULL,
				WNOHANG) != 0)
			break ;
	}
}

int	main(int argc, char **argv, char **env)
{
	int		fd[2];
	t_args	*args;

	if (argc != 5 || pipe(fd) == -1 || !env)
		return (127);
	args = init_struct(argc, argv, env);
	args->pid1 = fork();
	if (args->pid1 == -1)
		return (free_struct(args), 127);
	if (!args->pid1)
	{
		if (child(args->av, fd, args->env, args))
			return (free_struct(args), 127);
	}
	args->pid2 = fork();
	if (args->pid2 == -1)
		return (free_struct(args), 127);
	if (!args->pid2)
	{
		if (parent(args->av, fd, args->env, args))
			return (free_struct(args), 127);
	}
	shorten_main(args, fd);
	return (free_struct(args), 0);
}
