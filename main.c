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

void getPath(tsh1 *env) {
    int i = 0;
    while (env->env[i]) {
        if (!ft_strncmp(env->env[i], "PATH=", 5)) {
            env->path = ft_strsplit(env->env[i], ':');
        }
        i++;
    }
}

void parseEnv(void) {

}

int isExist(char *binarie, tsh1 all) {
    int i = 0;
    int len;
    DIR *dirp;
    struct dirent *dp;

    while (all.path[i]) {
        dirp = opendir(all.path[i]);
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


void parse(char *line, tsh1 all) {
    if (!ft_strcmp(line, "exit")) {
        exit(1);
    }
    else if (!ft_strncmp(line, "cd ", 3)) {
        char **split = ft_strsplit(line, ' ');
        DIR *dirp;


        if (split[1]) {
            dirp = opendir(split[1]);
            if (dirp != NULL) {
                int i = 0;
                while (all.env[i]) {
                    if (!ft_strncmp("PWD=", all.env[i], 4)) {
                        chdir(split[1]);
                        char *newpath = ft_strjoin("PWD=", split[1]);
                        all.env[i] = newpath;
                        break;
                    }
                    i++;
                }
            }
        }
        else {
            ft_putendl(ft_strjoin("cd: no such file or directory: ", split[1]));
        }
    }
    else if (!ft_strncmp(line, "setenv ", 7)) {
        exit(1);
    }
    else if (!ft_strncmp(line, "unsetenv ", 9)) {
        exit(1);
    }
    else if (ft_strcmp(line, "")) {
        char **split = ft_strsplit(line, ' ');

        int pathnb = isExist(split[0], all);
        if (pathnb != -1) {

            int child_status;
            pid_t pid;

            pid = fork();

            if (pid == 0) {
                execve(ft_strjoin(all.path[pathnb], ft_strjoin("/", split[0])), split, all.env);
                ft_putendl("error execve");
                exit(0);
            }
            else {
                while (waitpid(pid, &child_status, WNOHANG) == 0) {
                }
            }
        }
        else {
            ft_putendl("command not found");
        }
    }
}

int main(int ac, char **av, char **env) {
    (void) ac;
    (void) av;
    (void) env;
    tsh1 all;

    all.env = env;
    char *line = NULL;

    getPath(&all);
    all.path[0] = ft_strsub(all.path[0], 5, ft_strlen(all.path[0]) - 5);

    ft_putstr("bmikaeli $> ");

    while (get_next_line(1, &line)) {
        parse(line, all);
        ft_putstr("bmikaeli $> ");
    }
    return 0;
}