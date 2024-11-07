/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:18:14 by jrandet           #+#    #+#             */
/*   Updated: 2024/11/07 15:59:01 by jrandet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	ft_strlen(char *s1)
{
	int	i;

	i = 0;
	while (*s1)
	{
		s1++;
		i++;
	}
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
		*cursor++ = *s1++;
	*cursor = '\0';
	return (pt);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*joined_string;
	char	*ptr;
	size_t	total_len;

	if (!s1 && !s2)
		return (NULL);
	total_len = ft_strlen(s1) + ft_strlen(s2);
	joined_string = (char *)malloc(1 + sizeof(char) * total_len);
	if (!joined_string)
		return (NULL);
	ptr = joined_string;
	while (*s1)
		*ptr++ = *s1++;
	while (*s2)
		*ptr++ = *s2++;
	*ptr = '\0';
	return (joined_string);
}

char	*ft_substr(char *s1, unsigned int start, size_t len)
{
	char	*substr;
	char	*sub_ptr;
	size_t		str_len;

	if (!s1)
		return (NULL);
	str_len = ft_strlen(s1);
	if (start >= str_len)
		return (ft_strdup(""));
	if (len > str_len - start)
		len = str_len - start;
	substr = (char *)malloc(len + 1);
	if (!substr)
		return (NULL);
	sub_ptr = substr;
	s1 += start;
	while (*s1 && len--)
		*sub_ptr++ = *s1++;
	*sub_ptr = '\0';
	return (substr);
}

// int main()
// {
// 	char	*s1 = "Hello ";
// 	char	*s2 = "world\n";

// 	printf("the copied string is %s\n", ft_strjoin(s1, s2));
// 	return (0);
// }
