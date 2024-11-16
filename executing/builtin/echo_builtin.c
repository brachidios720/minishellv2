/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spagliar <spagliar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 10:26:20 by spagliar          #+#    #+#             */
/*   Updated: 2024/11/16 13:25:09 by spagliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_echo(char **argv, t_data *data, int fd)
{
	int		i;
	int		n_flag;
	char	*output;

	if (!argv[1])
	{
		ft_putstr_fd("\n", fd);
		return ;
	}
	n_flag = echo_n(argv[1]);
	i = n_flag;
	while (argv[i])
	{
		output = "fonction pour gerer les variables d extensions";
		if (output)
		{
			ft_putstr_fd(output, fd);
			free (output);
		}
		if (argv[i +1])
			ft_putstr_fd(" ", fd);
		i++;
	}
	if (!n_flag)
		ft_putstr_fd("\n", fd);
}

/*
1- si aucun argument passe apres echo
2- n-flag = verif si le 1er argu est -n
3- boucle pour gerer les arguments/options restantes
5- si fichier -> on ecrit la chaine traitee ds le fichier
4- si +1 -> les arguments sont separes par esp sauf dernier.
5- si pas -n -> saut de ligne

*/