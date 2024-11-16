#include "../include/minishell.h"

t_env	*init_env(char **envp)
{
	t_env *env_list; //ptr debut de liste qui a les variables 
    int i; //index

	env_list = NULL;
	i = 0;
	if (!envp)
		return NULL;
    while (envp[i])
    {
		t_env *new_node = ft_env_new(envp, i);
        if (new_node)
            ft_lstadd_back_list(&env_list, new_node);//ajout si reussite
        i++;
    }
    return (env_list);
}

void	init_pwd(t_env **env)
{
	char	*cwd;

	cwd = getcwd(NULL, PATH_MAX);
	ft_change_env(env, "PWD", cwd);
	ft_change_env(env, "OLDPWD", cwd);
	free(cwd);
}

void    init_data(t_data *data, char *str)
{
    //data->path = search_in_env(data, "PATH=");
    data->pwd = getcwd(NULL, PATH_MAX);
    data->old_pwd = data->pwd;
	if(ft_count_pipe(str) >= 1)
		data->cut_line = ft_split(str, '|'); //leaks
	else
		data->cut_line = ft_split(str, '\0'); //leaks 
	//data->last_exit_code = g_signal;
	data->line = ft_strdup(str); // leaks
}

void	init_data_and_cmd(char *line, t_data *data, t_cmd **cmd)
{
	t_cmd *newnode;

	cmd = malloc(sizeof(t_cmd *));
	*cmd = NULL;
	data = malloc(sizeof(t_data));
	init_data(data, line); // leaks
	int i = 0;
	while(data->cut_line[i])
	{
		newnode = ft_lsttnew(data, i, *cmd); //leaks
		i++;
		ft_lst_addbackk(cmd, newnode);
	}
}