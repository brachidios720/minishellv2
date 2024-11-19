#include "../include/minishell.h"


void ft_lstclearr(t_cmd **cmd)
{
    t_cmd *tmp;

    while (*cmd)
    {
        tmp = (*cmd)->next;
        free(*cmd);
        *cmd = tmp;
    }
}

void ft_free(char *str, t_cmd **cmd)
{
	ft_lstclearr(cmd);
	if (str != NULL && str[0] != '\0')
	{
		free(str);
		str = NULL;
	}
	if (cmd != NULL && *cmd != NULL)
	{
		free (*cmd);
		*cmd = NULL;
	}
}

