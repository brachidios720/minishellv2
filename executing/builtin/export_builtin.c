/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spagliar <spagliar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 18:22:40 by spagliar          #+#    #+#             */
/*   Updated: 2024/11/16 18:46:18 by spagliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_export(t_env **env, char **args)
{
	int i;

	if (!args[1])
	{
		export_with_nothing(*env);
		return ;
	}
	i = 1;
	while (args[i])
	{
		if ("fonction pour gerer les arguments valides")
			export_with_variable(*env, args[i]);
		else
			ft_printf("nom de varaiable invalide '%s'\n", args[i]);
		i++;
	}
}

void	export_with_nothing(t_env *env)
{
	t_env	*ptr;

	ptr = env;

	while (ptr)
	{
		printf("declare -x %s\n", ptr->content);
		ptr = ptr->next;
	}
}

void	export_with_variable(t_env *env, char *new_var)
{
	t_env	*ptr;
	t_env	*new_node;

	while (ptr)
	{
		if (ft_strncmp(ptr->content, new_var,
				ft_strchr(new_var, '=') - new_var) == 0)
		{
			free(ptr->content);
			ptr->content = ft_strdup(new_var);
			return ;
		}
		ptr = ptr->next;
	}
	new_node = ft_env_new(&new_var, 0);
	if (!new_node)
		return ;
	ft_lstadd_back_list(&env, new_node);
}
