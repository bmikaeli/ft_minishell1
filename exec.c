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

void do_cd(char *line, tsh1 *all) {
    char **split = ft_strsplit(line, ' ');
    DIR *dirp;
    if (split[2]) {
        ft_putendl("cd : too many arguments");
    }
    if (split[1]) {
        dirp = opendir(split[1]);
        if (dirp != NULL) {
            int i = 0;
            while (all->env[i]) {
                if (!ft_strncmp("PWD=", all->env[i], 4)) {
                    chdir(split[1]);
                    char *newpath = ft_strjoin("PWD=", split[1]);
                    all->env[i] = newpath;
                    break;
                }
                i++;
            }
        }
        else {
            ft_putendl(ft_strjoin("cd: no such file or directory: ", split[1]));
        }
    }
}


int isExist(char *binarie, tsh1 *all) {
    int i = 0;
    int len;
    DIR *dirp;
    int j = 0;
    struct dirent *dp;

    while (binarie[i] != '\0') {
        if (binarie[i] == '/')
            j = i;
        i++;
    }
    dirp = opendir(ft_strsub(binarie, 0, j + 1));

    if (dirp != NULL) {
        len = ft_strlen(binarie);
        while ((dp = readdir(dirp)) != NULL) {
            if (strcmp(dp->d_name, ft_strsub(binarie, j + 1, ft_strlen(binarie + 1))) == 0) {
                closedir(dirp);
                return (42);
            }
        }
    }
    i = 0;

    while (all->path[i]) {
        dirp = opendir(all->path[i]);
        if (dirp == NULL)
            return (-1);
        len = ft_strlen(binarie);
        while ((dp = readdir(dirp)) != NULL) {
            if (dp->d_namlen == len && strcmp(dp->d_name, binarie) == 0) {
                closedir(dirp);
                return (i);
            }
        }
        closedir(dirp);
        i++;
    }
    return (-1);
}

void exec(char **split, tsh1 *all, int pathnb) {
    int child_status;
    pid_t pid;

    pid = fork();

    if (pid == 0) {
        if (pathnb == 42) {
            execve(split[0], split, all->env);
        }
        else {
            execve(ft_strjoin(all->path[pathnb], ft_strjoin("/", split[0])), split, all->env);
        }
        ft_putendl("error execve");
        exit(0);
    }
    else {
        while (waitpid(pid, &child_status, WNOHANG) == 0) {
        }
    }
}