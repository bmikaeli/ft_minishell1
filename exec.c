/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/02 10:36:45 by bmikaeli          #+#    #+#             */
/*   Updated: 2015/06/02 10:36:46 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

int					isexistinpath(char *bin, t_sh1 *all)
{
	int				i;
	int				len;
	DIR				*dirp;
	struct dirent	*dp;

	i = 0;
	while (all->path[i])
	{
		dirp = opendir(all->path[i]);
		if (dirp == NULL)
			return (-1);
		len = ft_strlen(bin);
		while ((dp = readdir(dirp)) != NULL)
		{
			if (dp->d_namlen == len && strcmp(dp->d_name, bin) == 0)
			{
				closedir(dirp);
				return (i);
			}
		}
		closedir(dirp);
		i++;
	}
	return (-1);
}

int					isexist(char *bin, t_sh1 *all)
{
	int				i;
	DIR				*dirp;
	int				j;
	struct dirent	*dp;

	j = 0;
	i = 0;
	while (bin[i] != '\0')
	{
		if (bin[i] == '/')
			j = i;
		i++;
	}
	dirp = opendir(ft_strsub(bin, 0, j + 1));
	if (dirp != NULL)
	{
		while ((dp = readdir(dirp)) != NULL)
		{
			if (!strcmp(dp->d_name, ft_strsub(bin, j + 1, ft_strlen(bin + 1))))
			{
				return (42);
			}
		}
	}
	return (isexistinpath(bin, all));
}

void				exec(char **split, t_sh1 *all, int pathnb)
{
	int				child_status;
	pid_t			pid;

	pid = fork();
	if (pid == 0)
	{
		if (pathnb == 42)
			execve(split[0], split, all->env);
		else
			execve(ft_strjoin(all->path[pathnb],
				ft_strjoin("/", split[0])), split, all->env);
		ft_putendl("error execve");
		exit(0);
	}
	else
		while (!waitpid(pid, &child_status, WNOHANG))
		{
		}
}

void				do_cd(char *line, t_sh1 *all)
{
	char			**split;
	DIR				*dirp;
	int				i;
	char			*newpath;

	split = ft_strsplit(line, ' ');
	if (split[1])
	{
		dirp = opendir(split[1]);
		if (dirp != NULL)
		{
			i = 0;
			while (all->env[++i])
			{
				if (!ft_strncmp("PWD=", all->env[i], 4) && chdir(split[1]))
				{
					newpath = ft_strjoin("PWD=", split[1]);
					all->env[i] = newpath;
					break ;
				}
			}
		}
		else
			ft_putendl(ft_strjoin("cd: no such file or directory: ", split[1]));
	}
}
