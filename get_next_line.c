/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 14:36:49 by jrandet           #+#    #+#             */
/*   Updated: 2024/11/03 14:42:41 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h> //for testing

int main(int argc, char *argv)
{
	int		fd;
	char	buf[BUFF_SIZE];

	fd = open(argv[1], O_RDONLY);
	printf("file descriptor is %d\n", fd);


}