#ifndef FT_SH1
#define FT_SH1

#include <unistd.h>
#include <stdio.h>
#include "libft/includes/libft.h"
#include <dirent.h>

typedef struct ssh1 {
    char **env;
    char **path;
} tsh1;

int isExist(char *binarie, tsh1 *all);

void getPath(tsh1 *env);

int unsetEnv(char *toDelete, tsh1 *all);

int setEnv(char *toAdd, tsh1 *all);

void exec(char **split, tsh1 *all, int pathnb);

void do_cd(char *line, tsh1 *all);

void print_env(tsh1 *all);

#endif