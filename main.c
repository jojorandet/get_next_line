/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 20:45:22 by jrandet           #+#    #+#             */
/*   Updated: 2024/11/07 17:06:01 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

// int main(int argc, char **argv)
// {
// 	char		*line;
// 	int			fd;
// 	const char	*file_path;

// 	if (argc >= 2)
// 		file_path = argv[1];
// 	else
// 		file_path = "test.txt";
int	main(void)
{
	char		*line;
	int			fd;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
		return (-1);
	while ((line = get_next_line(fd)) != NULL)
	{
		write(1, line, ft_strlen(line));
		write(1, "\n", 1);
		free(line);
	}
	close(fd);
	return (0);
}