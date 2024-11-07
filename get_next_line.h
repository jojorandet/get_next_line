/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:18:41 by jrandet           #+#    #+#             */
/*   Updated: 2024/11/07 16:37:18 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 500
# endif

char	*get_next_line(int fd);
char	*ft_strdup(char *s1);
int		ft_strlen(char *s1);
int		find_next_line(char	*storage);
char	*fill_storage_until_nl(char **storage, int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_extract_line(char **storage, int pos_nl);
char	*ft_remainder(char	**storage, int pos_nl);
char	*ft_substr(char *s1, unsigned int start, size_t len);

#endif