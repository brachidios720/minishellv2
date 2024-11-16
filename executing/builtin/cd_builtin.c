/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spagliar <spagliar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 13:27:01 by spagliar          #+#    #+#             */
/*   Updated: 2024/11/16 17:48:35 by spagliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_update_env(t_env **env, char *old_dir, char *new_dir)
{
	if (old_dir)
		ft_change_env(env, "OLDPWD", old_dir);
	if (new_dir)
		ft_change_env(env, "PWD", new_dir);
}

/*
Role :effectue les opérations nécessaires pour changer de répertoire :
-Utilise getcwd pour récup. le rép. courant avant le changement (pour OLDPWD).
-Utilise chdir pour changer le rép. courant vers la cible spécifiée.
-Met à jour les variables d'env. PWD (nveau rép) et OLDPWD dans la liste t_env
via ft_change_env.
*/
void	ft_execute_cd(t_env **env, char *target_dir)
{
	char	*old_dir;
	char	*new_dir;

	old_dir = getcwd(NULL, PATH_MAX);
	if (!old_dir)
	{
		ft_putstr_fd("cd: erreur lors de la recup du rep courant\n", 2);
		return ;
	}
	if (ft_change_directory(target_dir) != 0)
	{
		ft_putstr_fd("cd: ", 2);
		perror(target_dir);
		free(old_dir);
		return ;
	}
	new_dir = getcwd(NULL, PATH_MAX);
	if (!new_dir)
	{
		ft_putstr_fd("cd: Erreur lors du nveau rep\n", 2);
		return ;
	}
	ft_update_env(env, old_dir, new_dir);
	free(old_dir);
	free(new_dir);
}

/*
rôle :  gérer la commande cd en orchestrant les différentes étapes nécessaires 
-analyser les arguments
-déterminer le répertoire cible
-gérer les erreurs
-effectuer le changement de répertoire.
*/
void	ft_cd(t_env **env, char **args)
{
	char	*target_dir;

	if (!ft_check_cd_args(args))
		return ;
	target_dir = ft_parse_target_dir(args, env);
	if (!target_dir)
		return ;
	ft_execute_cd(env, target_dir);
	free(target_dir);
}
/*
ft_update_env
-------------
Met à jour les variables d'env. PWD et OLDPWD après un changement de répertoire.
ft_execute_cd
-------------
Orchestre le changement de répertoire, gère les erreurs et appelle ft_update_env
ft_cd
-----
Point d'entrée principal pour gérer la commande cd, appelle les autres fonctions
*/