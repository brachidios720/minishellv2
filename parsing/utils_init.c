#include "../include/minishell.h"

void	ft_lstadd_back_list(t_env **env, t_env *new_node)
{
	t_env	*endnode;

	if (*env == NULL)
	{
		*env = new_node;
		return ;
	}
	endnode = *env;
	while (endnode->next) //parcourt tant qu on est pas a endnode
	{
		endnode = endnode->next;
	}
	endnode -> next = new_node; //si fin on pointe sur le nouveau
}
//creation d un nouveau noeud
t_env	*ft_env_new(char **envp, int i)
{
	t_env	*newnode;
	

	newnode = malloc(sizeof(t_env));
	if (!newnode)
		return (NULL);
	newnode->content = ft_strdup(envp[i]);
	newnode->next = NULL;
	return (newnode);
}

void	ft_change_env(t_env **env, char *name, char *new_value)
{
	t_env	*tmp;
	char	*new_content;
	int		name_len;
	int		value_len;
	int		total_len;

	tmp = *env;
	name_len = ft_strlen(name);
	value_len = ft_strlen(new_value);
	total_len = name_len + value_len + 2;
	while (tmp)
	{
		if (ft_strncmp(tmp->content, name, name_len) == 0
			&& tmp->content[name_len] == '=')
		{
			new_content = (char *)malloc(sizeof(char) * total_len);
			if (!new_content)
				return ;
			ft_strcpy(new_content, name);
			new_content[name_len] = '=';
			ft_strcpy(new_content + name_len + 1, new_value);
			free(tmp->content);
			tmp->content = new_content;
			return ;
		}
		tmp = tmp->next;
	}
}

int		ft_count_pipe(char *str)
{
	int i = 0;
	int y = 0;
	while(str[i])
	{
		if(str[i] == '|')
			y++;
		i++;
	}
	return(y);
}


void	ft_lst_addbackk(t_cmd **stack, t_cmd *node)
{
	t_cmd	*tmp;

	tmp = (*stack);
	if (tmp == NULL)
	{
		(*stack) = node;
		return ;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = node;
	node->next = NULL;
}