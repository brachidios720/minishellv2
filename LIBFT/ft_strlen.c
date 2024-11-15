/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelcarbonnel <raphaelcarbonnel@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 13:21:08 by spagliar          #+#    #+#             */
/*   Updated: 2024/09/04 18:41:10 by raphaelcarb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	if(!s)
		return(0);
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
