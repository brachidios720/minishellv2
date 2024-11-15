/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spagliar <spagliar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:13:49 by spagliar          #+#    #+#             */
/*   Updated: 2024/11/06 20:44:33 by spagliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlenn(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

// char	*ft_strjoinn(char *carstock, char *buff)
// {
// 	int		i;
// 	int		j;
// 	char	*result;

// 	i = 0;
// 	j = 0;
// 	if (!buff)
// 		return (carstock);
// 	result = malloc(sizeof(char) * (ft_strlenn(carstock) + ft_strlenn(buff)) + 1);
// 	if (!result)
// 		return (NULL);
// 	while (carstock[i])
// 	{
// 		result[i] = carstock[i];
// 		i++;
// 	}
// 	while (buff[j])
// 		result[i++] = buff[j++];
// 	result[i] = '\0';
// 	return (result);
// }

/*char	*ft_strchr(const char *s, int c)
{
	int			i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	if (!s[i])
		return (NULL);
	return ((char *)s);
}*/
