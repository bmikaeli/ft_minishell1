/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh1.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmikaeli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/03 11:14:22 by bmikaeli          #+#    #+#             */
/*   Updated: 2015/06/03 11:14:24 by bmikaeli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SH1_H
# define FT_SH1_H

# include <unistd.h>
# include <stdio.h>
# include "libft/includes/libft.h"
# include <dirent.h>

typedef struct	s_sh1 {
	char		**env;
	char		**path;
}				t_sh1;

int				isexist(char *binarie, t_sh1 *all);

void			getpath(t_sh1 *env);

int				ft_unsetenv(char *todelete, t_sh1 *all);

int				ft_setenv(char *toadd, t_sh1 *all);

void			exec(char **split, t_sh1 *all, int pathnb);

void			do_cd(char *line, t_sh1 *all);

void			print_env(t_sh1 *all);

#endif
