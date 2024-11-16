#include "../include/minishell.h"


void    ft_loop(t_env *env)
{
    t_data *data;
    t_cmd **cmd;

    data = NULL;
    cmd = NULL;
    (void)env;
    while(1)
    {
        char *line;
        line = readline(CYAN"Minishell> "RESET);
        if(ft_check_error(line) == 1 || !line)
            free(line);
        else if(line[0] != '\0')
        {
            init_data_and_cmd(line, data, cmd);
            // tu met ta fonction d'execution ici
            free(line);
        }
    }
}

int     ft_check_error(char *str)
{
    if(ft_check_option(str) == 1)
    {
        printf(RED"error\n"RESET);
        return(1);
    }
    return(0);
}

void    ft_start(char **envp)
{
    t_env *env;
    env = init_env(envp);
    init_pwd(&env);
    ft_loop(env);
}