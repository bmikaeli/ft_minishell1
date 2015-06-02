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

void parseEnv(void)
{

}

void parse(char *line)
{
    if(!ft_strcmp(line, "exit"))
    {
        exit(1);
    }
    if(!ft_strncmp(line, "cd ", 3))
    {
        exit(1);
    }
    if(!ft_strncmp(line, "setenv ", 7))
    {
        exit(1);
    }
    if(!ft_strncmp(line, "unsetenv ", 9))
    {
        exit(1);
    }
    if(ft_strcmp(line, ""))
    {
        ft_putendl("unknow command");
    }
}

int main(int ac, char **av, char **env)
{
    (void)ac;
    (void)av;
    (void)env;

    char *line = NULL;

    ft_putstr("bmikaeli $> ");

    while(get_next_line(1, &line))
    {
        parse(line);
        ft_putstr("bmikaeli $> ");
    }
    return 0;
}