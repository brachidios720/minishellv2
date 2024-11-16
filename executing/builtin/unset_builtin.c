/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spagliar <spagliar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 18:22:55 by spagliar          #+#    #+#             */
/*   Updated: 2024/11/16 18:54:04 by spagliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	unset_with_variable(t_env **env, char *my_var)
{
	t_env		**ptr;
	t_env		*tmp;
	char		*pos;
	int			len_name;

	ptr = env;
	while (*ptr)
	{
		pos = ft_strchr((*ptr)->content, '=');
		if (pos)
			len_name = pos - (*ptr)->content;
		if (ft_strncmp((*ptr)->content, my_var, len_name) == 0
			&& my_var[len_name] == '\0')
		{
			tmp = *ptr;
			*ptr = (*ptr)->next;
			free(tmp->content);
			free(tmp);
			return ;
		}
		ptr = &((*ptr)->next);
	}
}

int	ft_unset(t_env **env, char **args)
{
	int	i;

	if (!args[1])
	{
		return (1);
	}
	i = 1;
	while (args[i])
	{
		unset_with_variable(env, args[i]);
		i++;
	}
	return (0);
}
