/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/02 10:36:50 by bmikaeli          #+#    #+#             */
/*   Updated: 2015/06/02 10:36:50 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

void	print_env(t_sh1 *env)
{
	int	i;

	i = 0;
	while (env->env[i])
	{
		if (env->env[i][0] != '\0')
		{
			if (ft_strchr(env->env[i], '='))
				ft_putendl(env->env[i]);
		}
		i++;
	}
}

void	getpath(t_sh1 *env)
{
	int	i;

	i = 0;
	while (env->env[i])
	{
		if (!ft_strncmp(env->env[i], "PATH=", 5))
			env->path = ft_strsplit(env->env[i], ':');
		i++;
	}
}

int		ft_unsetenv(char *todelete, t_sh1 *all)
{
	int	i;
	int	found;

	i = 0;
	found = 0;
	while (all->env[i])
	{
		if (!found && !ft_strncmp(all->env[i], ft_strjoin(todelete, "="),
			ft_strlen(todelete + 1)))
		{
			all->env[i] = "\0";
			found = i;
		}
		i++;
	}
	if (found)
		return (1);
	return (0);
}

int		ft_setenv(char *toadd, t_sh1 *all)
{
	char	**split;
	char	**split2;
	int		i;

	split = ft_strsplit(toadd, ' ');
	if (!ft_strcmp(split[1], "PATH"))
		getpath(all);
	if (split[1] && split[2])
	{
		i = 0;
		while (all->env[i] && all->env[i][0] != '\0')
		{
			split2 = ft_strsplit(all->env[i], '=');
			if (!ft_strcmp(split2[0], split[1]))
				break ;
			i++;
		}
		all->env[i] = malloc(sizeof(char *) *
			ft_strlen(ft_strjoin(split[1], split[2])) + 1);
		all->env[i] = ft_strjoin(split[1], ft_strjoin("=", split[2]));
	}
	else
		return (-1);
	return (1);
}
