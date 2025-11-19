/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toespino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:34:00 by toespino          #+#    #+#             */
/*   Updated: 2025/11/19 14:21:10 by toespino         ###   ########.fr       */
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

char	*ft_strcpy_until(char *src)
{
	char	*out;
	int		i;

	out = malloc(ft_strlen(src) + 1);
	i = 0;
	while (src[i] && src[i] != '\n')
	{
		out[i] = src[i];
		i++;
	}
	return (out);
}

char	*ft_strcpy_since(char *src)
{
	char	*out;
	int		i;
	int		j;

	out = malloc(ft_strlen(src) + 1);
	i = 0;
	j = 0;
	while (src[i] && src[i])
		i++;
	while (src[i])
	{
		out[j] = src[i];
		i++;
		j++;
	}
	out[j] = '\0';
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
	out = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
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
	free(s1);
	return (out);
}
