/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelcarbonnel <raphaelcarbonnel@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:13:09 by spagliar          #+#    #+#             */
/*   Updated: 2024/09/04 17:41:25 by raphaelcarb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_cpy_line(char *line, char *carstock)
{
	int		i;

	i = 0;
	if (!carstock[i])
		return (NULL);
	while (carstock[i] && carstock[i] != '\n')
		i++;
	if (carstock[i] && carstock[i] == '\n')
		line = (char *)malloc(sizeof(char) * (i + 2));
	else
		line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (carstock[i] && carstock[i] != '\n')
	{
		line[i] = carstock[i];
		i++;
	}
	if (carstock[i] == '\n' && carstock[i])
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_new_carstock(char *carstock)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (carstock[i] != '\n' && carstock[i] != '\0')
		i++;
	if (!carstock[i])
	{
		free(carstock);
		return (NULL);
	}
	str = malloc(sizeof(char) * (ft_strlenn(carstock) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (carstock[i])
		str[j++] = carstock[i++];
	str[j] = '\0';
	free(carstock);
	return (str);
}

char	*ft_freejoin(char *carstock, char *buff)
{
	char	*temp;

	if (!carstock)
	{
		carstock = (char *)malloc(sizeof(char));
		if (!carstock)
			return (NULL);
		carstock[0] = '\0';
	}
	temp = ft_gnl_strjoin(carstock, buff);
	free(carstock);
	if (!temp)
		return (NULL);
	return (temp);
}

char	*ft_read_to_carstock(int fd, char *carstock)
{
	char	*buff;
	int		rd_bytes;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (rd_bytes > 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(carstock);
			free(buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		carstock = ft_freejoin(carstock, buff);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	free(buff);
	return (carstock);
}

char	*get_next_line(int fd)

{
	static char	*carstock[300];
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 300)
		return (NULL);
	carstock[fd] = ft_read_to_carstock(fd, carstock[fd]);
	if (!carstock[fd])
		return (NULL);
	line = ft_cpy_line(line, carstock[fd]);
	carstock[fd] = ft_new_carstock(carstock[fd]);
	return (line);
}
