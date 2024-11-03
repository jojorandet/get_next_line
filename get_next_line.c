/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 14:36:49 by jrandet           #+#    #+#             */
/*   Updated: 2024/11/03 21:30:16 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h> //for testing

int	ft_strlen(char *s1)
{
	int i;

	i = 0;
	while(*s1)
		i++;
	return (i);
}

int	find_new_line(char *remainder)
{
	int	i;

	while (*remainder)
	{
		if (remainder[i] == '\n')
			return i;
		i++;
	}
	return (-1);
}

char	*ft_extract_line(char **remainder)
{
	char	*line;
	char	*newremainder;
	int		newlinepos;

	newlinepos = find_newline(*remainder);
	if (newlinepos == -1)
		return (NULL);
	line = (char *)malloc(sizeof(char) * (newlinepos + 1));
	if (!line)
		return (NULL);
	ft_strncpy(line, *remainder, newlinepos);
	line[newlinepos] = '\0';
	newremainder = ft_strdup(*remainder + newlinepos + 1);
	if (!newremainder)
	{
		free (line);
		*line = (NULL);
		return (NULL);
	}
	free(*remainder);
	*remainder = newremainder;
	return (line);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*pointer;
	size_t	memory_needed;

	memory_needed = count * size;
	pointer = malloc(memory_needed);
	if (!pointer)
		return (NULL);
	ft_bzero(pointer, memory_needed);
	return (pointer);
}

char	*get_next_line(int fd);
{
	static char		*remainder;
	char			buffer[BUFF_SIZE];
	ssize_t			bytesread;
	char			*line;
	
	if (*remainder = '\0')
		remainder = ft_calloc(1, 1);
	line = ft_extract_line(&remainder);
	if (!line)
		return (NULL);
	while (true)
	{
		bytesread = read(fd, buffer, BUFF_SIZE)
		if (bytesread == 0)
			if ((remainder != NULL) && (*remainder != '\0'))
				
	}
	
}

/*int main(int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc < 2)
		return (-1);
	if (!line)
		return (-1);
	fd = open(argv[1],O_RDONLY);
	if (fd == -1)
		return (-1);
	while ((line = get_next_line(fd)) != NULL)
	{
		write(1, line, ft_strlen(line));
		free(line);
	}
}*/
