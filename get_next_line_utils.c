/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 16:39:19 by jrandet           #+#    #+#             */
/*   Updated: 2024/11/03 21:30:18 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void	*dst, const void *src, size_t n)
{
	unsigned char		*d1;
	const unsigned char	*s1;

	if (!dst || !src)
		return (NULL);
	d1 = (unsigned char *)dst;
	s1 = (const unsigned char *)src;
	while (n--)
		*d1++ = *s1++;
	return (dst);
}

char	*ft_strdup(char *s)
{
	char	*duplicate;
	size_t	len;

	if (*s == '\0')
		return (ft_calloc(1, 1));
	len = ft_strlen(s);
	duplicate = (char *)malloc(sizeof(char) * (len + 1));
	if (!duplicate)
		return (NULL);
	ft_memcpy(duplicate, s, len + 1);
	return (duplicate);
}

void	ft_strncpy(char *dst, char *src, size_t n)
{
	char	*cursor;

	if (!dst || !src)
		return ;
	cursor = dst;
	while (*src && n--)
		*cursor++ = *src++;
	*cursor = '\0';
}
