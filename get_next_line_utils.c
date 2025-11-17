/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toespino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:34:00 by toespino          #+#    #+#             */
/*   Updated: 2025/11/15 15:03:01 by toespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	srclen;
	size_t	i;

	srclen = 0;
	i = 0;
	while (src[srclen])
		srclen++;
	if (size > 0)
	{
		while (i < size - 1 && i < srclen)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (srclen);
}

char	*ft_substr(int start, char *str, int len)
{
	char	*out;
	size_t	lens;

	if (!s)
		return (NULL);
	lens = ft_strlen(s);
	if (start >= lens)
		return (ft_strdup(""));
	if (lens - start < len)
		len = lens - start;
	out = malloc(len + 1);
	if (!out)
		return (NULL);
	ft_strlcpy(out, &s[start], len + 1);
	return (out);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*out;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	out = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!out)
		return (NULL);
	while (s1[i])
	{
		out[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		out[i] = s2[j];
		i++;
		j++;
	}
	return (out);
}
