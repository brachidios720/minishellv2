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