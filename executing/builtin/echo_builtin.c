/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spagliar <spagliar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 10:26:20 by spagliar          #+#    #+#             */
/*   Updated: 2024/11/18 18:59:58 by spagliar         ###   ########.fr       */
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
	//ft_args_for_echo(argv, data, fd);
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
	char	*output;

	while (*argv)
	{
		//outpout = expand_variables_in_string(*argv, data);
		if (output)
		{
			ft_putstr_fd(output, fd);
			free (output);
		}
		if (argv +1)
			ft_putstr_fd(" ", fd);
		argv++;
	}
}

char *expand_variables_in_string(char *str, t_data *data) 
{
	char *result = NULL;
    int i = 0;
    int start;
    char *var_name;
    char *var_value;

    while (str[i] != '\0') 
	{
		//if(str[i] == '$' && str[i + 1] == '?')
		//{
		//	result = last_exit(data);
		//	i += 2;
	}
        if (str[i] == '$') 
		{  // Détecte le début d'une variable
			i++;
            start = i;
            while (str[i] != '\0' && ft_isalpha(str[i]) == 1) {
                i++;
            }

            var_name = ft_substr(str, start, i - start);  // Extrait le nom de la variable

            // Recherche la valeur de la variable dans l'environnement
            var_value = getenv(var_name); 
            if (var_value == NULL) {
                var_value = "";  // Si la variable n'est pas trouvée, remplace par une chaîne vide
            }
            result = ft_strjoinn(result, var_value);  // Concatène la chaîne
            free(var_name);  // Libère le nom de la variable
        } else {
            // Si ce n'est pas une variable, on ajoute le caractère au résultat
     		result = ft_strjoin_char(result, str[i]);// Ajoute chaque caractère individuel
            i++;
        }
    }
	//printf("Résultat final : %s\n", result);
    return result;  // Retourne le résultat final
}