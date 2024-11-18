#include "../include/minishell.h"

int     ft_check_option(char *str)
{
    if(ft_check_pipe(str) == 1)
        return(1);
    else if(ft_check_quote(str) == 1)
        return(1);
    else
        return(0);
}

int ft_check_pipe(char *str)
{
    int i = 0;
    if(str != NULL)
    {
        while(str[i] == ' ' && str[i])
        {
            i++;
        }
        if(str[i] == '|')
            return(1);
        while(str[i])
            i++;
        if(str[i - 1] == '|')
            return(1);
        return(0);
    }
    return(0);
}

int     ft_check_quote(char *str)
{
    int i = 0;
    int y = 0;
    int x = 0;
    while(str && str[i])
    {
        if(str[i] == '\"')
            y++;
        if(str[i] == '\'')
            x++;
        i++;
    }
    if(y % 2 == 1 || x % 2 == 1)
        return(1);
    return(0);
}