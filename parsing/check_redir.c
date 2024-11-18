#include "../include/minishell.h"

bool	check_if_heredoc(char *str)
{
	int i = 0;
	while(str[i])
	{
		if(str[i] == '<' && str[i + 1] == '<')
			return(TRUE);
		i++;
	}
	return(FALSE);
}

