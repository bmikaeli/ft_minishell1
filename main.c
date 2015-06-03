/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/02 10:36:33 by bmikaeli          #+#    #+#             */
/*   Updated: 2015/06/02 10:36:34 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sh1.h"

void		parse2(char *line, t_sh1 *all)
{
	char	**split;
	int		pathnb;

	if (!ft_strcmp(line, "exit"))
		exit(1);
	else if (!ft_strncmp(line, "cd ", 3))
		do_cd(line, all);
	else if (!ft_strncmp(line, "setenv ", 7))
		ft_setenv(line, all);
	else if (!ft_strcmp(line, "env"))
		print_env(all);
	else if (!ft_strncmp(line, "unsetenv ", 9))
		ft_unsetenv(ft_strsplit(line, ' ')[1], all);
	else if (ft_strcmp(line, ""))
	{
		split = ft_strsplit(line, ' ');
		pathnb = isexist(split[0], all);
		if (pathnb != -1)
			exec(split, all, pathnb);
		else
			ft_putendl("command not found");
	}
}

void		parse(char *line, t_sh1 *all)
{
	char	**allcmd;
	int		i;

	i = 0;
	allcmd = ft_strsplit(line, ';');
	while (allcmd != NULL && allcmd[i] && ft_strtrim(allcmd[i])[0])
	{
		parse2(allcmd[i], all);
		i++;
	}
}

char		*trimline(char *line)
{
	char	*ret;
	int		i;
	int		j;

	ret = malloc(sizeof(char *) * ft_strlen(line));
	i = 0;
	j = 0;
	while (line[i] && line[i] != '\0')
	{
		if ((line[i] == ' ' || line[i] == '\t') && ret[j - 1] == ' ')
		{
			i++;
			continue;
		}
		if (line[i] == '\t')
			ret[j] = ' ';
		else
			ret[j] = line[i];
		j++;
		i++;
	}
	ret[j] = '\0';
	return (ret);
}

int			main(int ac, char **av, char **env)
{
	char	*line;
	t_sh1	all;

	(void)ac;
	(void)av;
	if (env[0] == NULL)
	{
		ft_putendl("Env null");
		exit(-1);
	}
	all.env = env;
	line = NULL;
	getpath(&all);
	all.path[0] = ft_strsub(all.path[0], 5, ft_strlen(all.path[0]) - 5);
	ft_putstr("bmikaeli $> ");
	while (get_next_line(1, &line))
	{
		line = trimline(ft_strtrim(line));
		parse(line, &all);
		ft_putstr("bmikaeli $> ");
	}
	return (0);
}
