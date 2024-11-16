/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spagliar <spagliar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 18:23:12 by spagliar          #+#    #+#             */
/*   Updated: 2024/11/16 18:50:06 by spagliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	is_builtin(char *cmd)
{
	if (ft_strncmp(cmd, "env", ft_strlen("env")) == 0
		|| ft_strncmp(cmd, "cd", ft_strlen("cd")) == 0
		|| ft_strncmp(cmd, "echo", ft_strlen("echo")) == 0
		|| ft_strncmp(cmd, "pwd", ft_strlen("pwd")) == 0
		|| ft_strncmp(cmd, "export", ft_strlen("export")) == 0
		|| ft_strncmp(cmd, "unset", ft_strlen("unset")) == 0)
		return (1);
	return (0);
}
