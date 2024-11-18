#include "../include/minishell.h"


char    *check_delimiteur(char *str)
{
    int i = 0;
    int j = 0;
    char *delimiteur;

    while(str[i])
    {
        if(str[i] == '<' && str[i + 1] == '<')
        {
            i += 2;
            while(str[i] == ' ' || str[i] == '\t')
                i++;
            j = i;
            while(str[i] != ' ' && str[i] != '\t' && str[i])
                i++;
            delimiteur = malloc(sizeof(char) * i - j);
            if(!delimiteur)
                return(NULL);
            delimiteur = ft_strncpy(&str[j], delimiteur, i -j);
            return(delimiteur);
        }
        i++;
    }
    return(NULL);
}



void   init_heredoc(t_cmd *newnode, t_data *data, int i)
{
    newnode->heredoc = check_if_heredoc(data->line);
    if(newnode->heredoc == TRUE)
    {
        newnode->delimiter = check_delimiteur(data->cut_line[i]);
    }
}