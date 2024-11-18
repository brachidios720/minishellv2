/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spagliar <spagliar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 11:46:38 by spagliar          #+#    #+#             */
/*   Updated: 2024/11/18 17:24:47 by spagliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//a laisser pour raph parsing
#include "../../include/minishell.h"

char	*ft_itoa_m(int n)
{
	char	buff[12];
	long	nb;
	int		i;
	int		negatif;

	i = 0;
	nb = (long)n;
	negatif = 0;
	if (!nb)
		return (ft_zero());
	if (nb < 0)
	{
		negatif = 1;
		nb = -nb;
	}
	while (nb)
	{
		buff[i++] = (nb % 10) + 48;
		nb /= 10;
	}
	if (negatif)
		buff[i++] = '-';
	buff[i] = '\0';
	return (ft_return(buff));
}

//pour $
char    *ft_strjoinn(char const *s1, char const *s2)
{
    size_t len1 = 0;
    size_t len2 = 0;
    char *strj;

    if (s1) len1 = ft_strlen(s1);  // S'assurer que s1 n'est pas NULL
    if (s2) len2 = ft_strlen(s2);  // S'assurer que s2 n'est pas NULL

    strj = malloc(len1 + len2 + 1);
    if (strj == NULL)
        return NULL;

    if (s1) ft_memcpy(strj, s1, len1);  // Copier s1 si ce n'est pas NULL
    if (s2) ft_memcpy(strj + len1, s2, len2);  // Copier s2 si ce n'est pas NULL

    strj[len1 + len2] = '\0';  // Ajouter le caractère de fin de chaîne
    return strj;
}

char *ft_strjoin_char(char *s1, char c) {
    int len;
    char *result;

    if (s1 != NULL)
        len = strlen(s1);
    else
        len = 0;

    result = malloc(len + 2);  // +2 pour le caractère et le '\0'
    if (result == NULL)
        return NULL;

    if (s1 != NULL)
        strcpy(result, s1);
    
    result[len] = c;
    result[len + 1] = '\0';

    free(s1);  // Libère s1 si elle a été allouée dynamiquement
    return result;
}

//exit code
char *last_exit(t_data *data)
{
	char *value;
	//i += 2;

	value = ft_itoa_m(data->last_exit_code);
	return(value);

}

int check_dollard(char *str)
{
	int i = 0;
	int count = 0;
	while(str[i])
	{
		if(str[i] == '$')
			count++;
		i++;
	}
	return(count);
}