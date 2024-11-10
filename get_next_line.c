/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:15:18 by jrandet           #+#    #+#             */
/*   Updated: 2024/11/10 17:45:54 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
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

char	*updated_stash(char **old_stash) //changes the stash directly, so we need 
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
		len++; // will read the whole string
	if (stash[len] == '\n')
		len++; //this accounts for the \n
	line = ft_substr(stash, 0, len); //it extracts the entire string even if no \n
	return (line);
}

char	*read_and_append(char *stash, int fd)
{
	int		bytes_read;
	char	buff[BUFFER_SIZE + 1];
	char	*temp;

	bytes_read = read(fd, buff, BUFFER_SIZE);
	if (bytes_read == 0)
		return (stash);
	while (bytes_read > 0)
	{
		buff[bytes_read] = '\0';
		temp = ft_strjoin(stash, buff);
		if (!temp)
			return (free_and_return_null(&stash));
		free(stash);
		stash = temp;
		bytes_read = read(fd, buff, BUFFER_SIZE);
	}
	if (bytes_read == -1)
		return (free_and_return_null(&stash));
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!stash)
	{
		stash = ft_strdup("");
		if (!stash)
			return (stash);
	}
	stash = read_and_append(stash, fd);
	if (!stash)
		return (free_and_return_null(&stash));
	if (*stash == '\0') //EMPTY STRING CASE IF SO WE DO NOT NEED a stash
		return (free_and_return_null(&stash));
	line = extract_line(stash); //even if we have "abcdefju"
	if (!line)
		return (free_and_return_null(&stash));
	stash = updated_stash(&stash);
	return (line);
}