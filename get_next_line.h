/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 14:34:53 by jrandet           #+#    #+#             */
/*   Updated: 2024/11/03 21:27:17 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

# define BUFF_SIZE 1024

char		*get_next_line(int fd);
void		*ft_calloc(size_t count, size_t size);
char		*ft_extract_line(char **remainder);
int			ft_strlen(char *s1);
void		*ft_memcpy(void	*dst, const void *src, size_t n);
char		*ft_strdup(char *s);
void		ft_strncpy(char *dst, char *src, size_t n);



#endif