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


void parse(char *line, tsh1 *all) {
    char **allcmd = ft_strsplit(line, ';');
    int i = 0;

    while (allcmd != NULL && allcmd[i] && ft_strtrim(allcmd[i])[0]) {
            if (!ft_strcmp(allcmd[i], "exit")) {
                exit(1);
            }
            else if (!ft_strncmp(allcmd[i], "cd ", 3)) {
                do_cd(allcmd[i], all);
            }
            else if (!ft_strncmp(allcmd[i], "setenv ", 7)) {
                setEnv(allcmd[i], all);
            }
            else if (!ft_strcmp(allcmd[i], "env")) {
                print_env(all);
            }
            else if (!ft_strncmp(allcmd[i], "unsetenv ", 9)) {
                unsetEnv(ft_strsplit(allcmd[i], ' ')[1], all);
            }
            else if (ft_strcmp(allcmd[i], "")) {
                char **split = ft_strsplit(allcmd[i], ' ');

                int pathnb = isExist(split[0], all);
                if (pathnb != -1) {
                    exec(split, all, pathnb);
                }
                else {
                    ft_putendl("command not found");
                }
            }
            i++;
    }
}

char *trimLine(char *line) {
    char *ret = malloc(sizeof(char *) * ft_strlen(line));
    int i = 0;
    int j = 0;
    while (line[i] && line[i] != '\0') {
        if ((line[i] == ' ' || line[i] == '\t') && ret[j - 1] == ' ') {
            i++;
            continue;
        }
        if (line[i] == '\t') {
            ret[j] = ' ';
        }
        else {
            ret[j] = line[i];
        }
        j++;
        i++;
    }
    ret[j] = '\0';
    return ret;
}

int main(int ac, char **av, char **env) {
    (void) ac;
    (void) av;

    if (env[0] == NULL) {
        ft_putendl("Env null");
        exit(-1);
    }
    tsh1 all;
    all.env = env;

    char *line = NULL;
    getPath(&all);
    all.path[0] = ft_strsub(all.path[0], 5, ft_strlen(all.path[0]) - 5);

    ft_putstr("bmikaeli $> ");

    while (get_next_line(1, &line)) {
        line = trimLine(line);
        parse(line, &all);
        ft_putstr("bmikaeli $> ");
    }
    return 0;
}