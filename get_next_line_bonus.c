/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:15:18 by jrandet           #+#    #+#             */
/*   Updated: 2024/11/13 18:59:14 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

char	*free_and_return_null(char **stash)
{
	if (*stash)
	{
		free(*stash);
		*stash = NULL;
	}
	return (NULL);
}

char	*updated_stash(char **old_stash)
{
	char	*new_stash;
	int		len;

	len = 0;
	if (!*old_stash)
		return (NULL);
	while ((*old_stash)[len] && (*old_stash)[len] != '\n')
		len++;
	if ((*old_stash)[len] == '\0')
		return (free_and_return_null(old_stash));
	len++;
	new_stash = ft_substr(*old_stash, len, ft_strlen(*old_stash) - len);
	if (!new_stash)
		return (free_and_return_null(old_stash));
	free(*old_stash);
	*old_stash = new_stash;
	return (new_stash);
}

char	*extract_line(char *stash)
{
	int		len;
	char	*line;

	len = 0;
	if (!stash)
		return (NULL);
	while (stash[len] && stash[len] != '\n')
		len++;
	if (stash[len] == '\n')
		len++;
	line = ft_substr(stash, 0, len);
	return (line);
}

char	*read_and_append(char *stash, int fd)
{
	int		bytes_read;
	char	buff[BUFFER_SIZE + 1];
	char	*temp;

	bytes_read = read(fd, buff, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buff[bytes_read] = '\0';
		temp = ft_strjoin(stash, buff);
		if (!temp)
			return (free_and_return_null(&stash));
		free(stash);
		stash = temp;
		if (ft_strchr(stash, '\n'))
			break ;
		bytes_read = read(fd, buff, BUFFER_SIZE);
	}
	if (bytes_read == -1)
		return (free_and_return_null(&stash));
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash_array[MAX_FD];
	char		*line;

	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (free_and_return_null(&stash_array[fd]));
	if (!stash_array[fd])
	{
		stash_array[fd] = ft_strdup("");
		if (!stash_array[fd])
			return (NULL);
	}
	stash_array[fd] = read_and_append(stash_array[fd], fd);
	if (!stash_array[fd] || !*stash_array[fd])
		return (free_and_return_null(&stash_array[fd]));
	line = extract_line(stash_array[fd]);
	if (!line || line[0] == '\0')
		return (free_and_return_null(&stash_array[fd]));
	stash_array[fd] = updated_stash(&stash_array[fd]);
	return (line);
}
