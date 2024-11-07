/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:18:17 by jrandet           #+#    #+#             */
/*   Updated: 2024/11/07 17:07:39 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_remainder(char	**storage, int pos_nl)
{
	char	*temp_storage;
	size_t	remaining_len;

	remaining_len = ft_strlen(*storage) - pos_nl - 1;
	temp_storage = ft_substr(*storage, pos_nl + 1, remaining_len);
	if (!temp_storage)
		return (NULL);
	return (temp_storage);
}

char	*ft_extract_line(char **storage, int pos_nl)
{
	char		*temp_storage;
	char		*line;

	line = ft_substr(*storage, 0, pos_nl);
	if (!line)
	{
		free (*storage);
		*storage = NULL;
		return (NULL);
	}
	temp_storage = ft_remainder(storage, pos_nl);
	if (!temp_storage)
	{
		free (line);
		return (NULL);
	}
	free (*storage);
	*storage = temp_storage;
	return (line);
}

int	find_next_line(char	*storage)
{
	int	i;

	i = 0;
	while (storage[i])
	{
		if (*storage == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*fill_storage_until_nl(char **storage, int fd)
{
	char		buff[BUFFER_SIZE + 1];
	int			bytesread;
	char		*temp;

	while (1)
	{
		bytesread = read(fd, buff, BUFFER_SIZE);
		if (bytesread <= 0)
		{
			*storage = NULL;
			break ;
		}	
		buff[bytesread] = '\0';
		temp = ft_strjoin(*storage, buff);
		if (!temp)
			return (NULL);
		free (*storage);
		*storage = temp;
		if (find_next_line(*storage) != -1)
			break ;
	}
	if (bytesread == 0 && **storage == '\0')
	{
		free(*storage);
		*storage = NULL;
		return (NULL);
	}
	return (*storage);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	int			pos_nl;
	char		*line;

	if (fd == -1)
		return (NULL);
	if (!storage)
		storage = ft_strdup("");
	if (!storage)
		return (NULL);
	if (!fill_storage_until_nl(&storage, fd))
		return (NULL);
	pos_nl = find_next_line(storage);
	if (pos_nl == -1)
	{
		line = ft_strdup(storage);
		free (storage);
		storage = NULL;
		return (line);
	}
	line = ft_extract_line(&storage, pos_nl);
	return (line);
}
