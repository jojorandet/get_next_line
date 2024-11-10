/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:00:43 by jrandet           #+#    #+#             */
/*   Updated: 2024/11/10 13:09:46 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

int		ft_strlen(char *str);
char	*ft_strjoin(char *str1, char *str2);
char	*ft_substr(char	*s1, int start_pos, int sub_len);
char	*get_next_line(int fd);
char	*read_and_append(char *stash, int fd);
char	*extract_line(char *stash);
char	*updated_stash(char **stash);
char	*ft_strdup(char *s1);
void	ft_free(void *ptr);
char	*free_and_return_null(char **stash);

#endif