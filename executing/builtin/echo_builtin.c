/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spagliar <spagliar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 10:26:20 by spagliar          #+#    #+#             */
/*   Updated: 2024/11/16 18:10:58 by spagliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_echo(char **argv, t_data *data, int fd)
{
	int		i;
	int		n_flag;

	if (!argv[1])
	{
		ft_putstr_fd("\n", fd);
		return ;
	}
	i = 1;
	n_flag = false;
	while (argv[i] && echo_n(argv[i]))
	{
		n_flag = true;
		i++;
	}
	ft_args_for_echo(argv, data, fd);
	if (!n_flag)
		ft_putstr_fd("\n", fd);
}

/*
Return booléen pour indiquer si l'argu. correspd à une option -n valide.
1-Si argv est NULL, ne com. pas par '-',ou si le car. suiv. n'est pas 'n'
2-boucle apres après le 1er '-' pour vérif. les car. suiv. sont des 'n'
3-si apres n -> fin de la chaine = true ou sinon = false
*/
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
1- si aucun argument passe apres echo
2- n-flag = verif si le 1er argu est -n
3- boucle pour gerer les arguments/options restantes
5- si fichier -> on ecrit la chaine traitee ds le fichier
4- si +1 -> les arguments sont separes par esp sauf dernier.
5- si pas -n -> saut de ligne

*/
void	ft_args_for_echo(char **argv, t_data *data, int fd)
{
	char	*outpout;

	while (*argv)
	{
		outpout = expand_variables_in_string(*argv, data);
		if (outpout)
		{
			ft_putstr_fd(outpout, fd);
			free (outpout);
		}
		if (argv +1)
			ft_putstr_fd(" ", fd);
		argv++;
	}
}

