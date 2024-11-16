#include "../include/minishell.h"

t_cmd	*ft_lsttnew(t_data *data, int i, t_cmd *cmd)
{
    (void)cmd;
	t_cmd	*newnode;

	newnode = malloc(sizeof(t_cmd));
	if (!newnode)
		return (NULL);
   // init_cmd(newnode);
    newnode->cmd = ft_splitt(data->cut_line[i], ' ');
    //trim_quotes(newnode->cmd);
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