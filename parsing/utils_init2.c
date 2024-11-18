#include "../include/minishell.h"

t_cmd	*ft_lsttnew(t_data *data, int i, t_cmd *cmd)
{
    (void)cmd;
	t_cmd	*newnode;
    int y = 0;
    int j = 0;

	newnode = malloc(sizeof(t_cmd));
	if (!newnode)
		return (NULL);
   // init_cmd(newnode);
    newnode->cmd = ft_splitt(data->cut_line[i], ' ');
    trim_quotes(newnode->cmd);
    while(newnode->cmd[y])
    {
        printf("new node ->cmd %d = %s\n",j , newnode->cmd[y]);
        j++;
        y++;
    }
    init_heredoc(newnode, data, i);
    printf("delimiteur = %s\n", newnode->delimiter);
    newnode->next = NULL;
	return (newnode);
}

int	ft_lstsizee(t_cmd *cmd)
{
	int	i;

	i = 0;
	while (cmd)
	{
		cmd = cmd->next;
		i++;
	}
	return (i);
}

void	is_a_quote(char c, int *state)
{
	if (c == '\'' && *state == 0)
		*state = 1;
	else if (c == '\'' && *state == 1)
		*state = 0;
	if (c == '\"' && *state == 0)
		*state = 2;
	else if (c == '\"' && *state == 2)
		*state = 0;
}

void	shift_str(char *str, int length)
{
	int	i;

	i = 0;
	while (str[i + length])
	{
		str[i] = str[i + length];
		i++;
	}
	str[i] = '\0';
}

void	trim_quotes(char **option)
{
	int	i;
	int	j;
	int	state;
	
	state = 0;
	i = 0;
	while (option[i])
	{
		j = 0;
		while (option[i][j])
		{
			is_a_quote(option[i][j], &state);
			if ((option[i][j] == '\"' && state != 1)
				|| (option[i][j] == '\'' && state != 2))
			{
				shift_str((option[i] + j), 1);
				j--;
			}
			if (j < (int)ft_strlen(option[i]))
				j++;
		}
		i++;
	}
}