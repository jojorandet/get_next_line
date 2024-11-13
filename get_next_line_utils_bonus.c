/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 20:36:43 by jrandet           #+#    #+#             */
/*   Updated: 2024/11/13 17:31:22 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s && (*s != (char)c))
		s++;
	if (*s == (char)c)
		return ((char *)s);
	else
		return (NULL);
}

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s1)
{
	char	*pt;
	char	*cursor;
	int		len;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	pt = (char *)malloc(sizeof(char) * (len + 1));
	if (!pt)
		return (NULL);
	cursor = pt;
	while (*s1)
	{
		*cursor = *s1;
		cursor++;
		s1++;
	}
	*cursor = '\0';
	return (pt);
}

char	*ft_strjoin(char *str1, char *str2)
{
	int		total_len;
	char	*new_string;
	char	*current;

	if (!str1 || !str2)
		return (NULL);
	total_len = ft_strlen(str1) + ft_strlen(str2);
	new_string = (char *)malloc(sizeof(char) * (total_len + 1));
	if (!new_string)
		return (NULL);
	current = new_string;
	while (*str1)
		*current++ = *str1++;
	while (*str2)
		*current++ = *str2++;
	*current = '\0';
	return (new_string);
}

char	*ft_substr(char	*s1, int start_pos, int sub_len)
{
	int		s1_len;
	char	*extracted_string;
	char	*current;

	if (!s1)
		return (NULL);
	s1_len = ft_strlen(s1);
	if (start_pos > s1_len)
		return (NULL);
	if (sub_len > s1_len - start_pos)
		sub_len = s1_len - start_pos;
	extracted_string = (char *)malloc(sizeof(char) * (sub_len + 1));
	if (!extracted_string)
		return (NULL);
	s1 += start_pos;
	current = extracted_string;
	while (*s1 && sub_len--)
		*current++ = *s1++;
	*current = '\0';
	return (extracted_string);
}
