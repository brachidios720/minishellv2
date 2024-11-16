/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spagliar <spagliar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 11:46:38 by spagliar          #+#    #+#             */
/*   Updated: 2024/11/16 13:25:32 by spagliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*Return booléen pour indiquer si l'argu. correspd à une option -n valide.*/
bool	echo_n(char *argv)
{
	int	i;

	if (!argv || argv[0] != '-' || argv[1] != 'n')
		return (false);
	i = 1;
	while (argv[i] == 'n')
		i++;
	if (argv[i] == '\0')
		return (true);
	return (false);
}
/*
1- Si argv est NULL, ne com. pas par '-', ou si le car. suiv. n'est pas 'n'
2- boucle apres après le 1er '-' pour vérif. les car. suiv. sont des 'n'
3- si apres n -> fin de la chaine = true ou sinon = false
*/