/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spagliar <spagliar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 10:18:43 by spagliar          #+#    #+#             */
/*   Updated: 2024/11/16 17:45:55 by spagliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*find_command_path(char *cmd)
{
	char	*path;
	char	**paths;
	char	*full_path;
	int		i;

	path = getenv("PATH");
	paths = ft_split(path, ':');
	i = 0;
	while (paths[i])
	{
		full_path = ft_strjoin(paths[i], "/");
		full_path = ft_strjoin(full_path, cmd);
		if (access(full_path, X_OK) == 0)
			return (full_path);
		i++;
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	char	*result;

	if (argc != 2)
	{
		printf ("Usage: %s <commande>\n", argv[0]);
		return (1);
	}
	result = find_command_path(argv[1]);
	if (result != NULL)
		printf ("Chemin absolu yeah : %s\n", result);
	else
		printf ("Commande non trouvée dans PATH.\n");
	return (0);
}
//attention verif chemins relatifs et absolus
