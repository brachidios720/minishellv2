/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spagliar <spagliar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:05:35 by spagliar          #+#    #+#             */
/*   Updated: 2024/11/16 17:42:38 by spagliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*ft_get_env_value(char *name, t_env **env)
{
	t_env	*tmp;

	tmp = *env;
	while (tmp)
	{
		if (ft_strncmp(tmp->content, name, ft_strlen(name)) == 0
			&& tmp->content[ft_strlen(name)] == '=')
			return (tmp->content + ft_strlen(name) + 1);
		tmp = tmp->next;
	}
	return (NULL);
}

char	*ft_parse_target_dir(char **args, t_env **env)
{
	char	*target_dir;

	if (!args[1] || ft_strcmp(args[1], "~") == 0)
	{
		target_dir = ft_get_env_value("HOME", env);
		if (!target_dir)
			ft_putstr_fd("cd: HOME not set\n", 2);
	}
	else if (ft_strcmp(args[1], "-") == 0)
	{
		target_dir = ft_get_env_value("OLDPWD", env);
		if (!target_dir)
			ft_putstr_fd("cd: OLDPWD not set\n", 2);
	}
	else
		target_dir = args[1];
	if (target_dir)
		return (ft_strdup(target_dir));
	else
		return (NULL);
}

int	ft_change_directory(char *target_dir)
{
	if (chdir(target_dir) != 0)
		return (0);
	return (1);
}

int	ft_check_cd_args(char **args)
{
	int	count;

	count = 0;
	while (args[count])
		count++;
	if (count > 2)
	{
		ft_putstr_fd("cd: too many arguments\n", 2);
		return (0);
	}
	return (1);
}
