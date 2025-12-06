/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toespino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 11:59:09 by toespino          #+#    #+#             */
/*   Updated: 2025/12/06 18:06:32 by toespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_free(char *s1, char *s2)
{
	free(s1);
	free(s2);
	return (NULL);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strchr(char *str, int c)
{
	int	out;
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
		{
			out = 1;
			break ;
		}
		i++;
	}
	return (out);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*out;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL)
	out = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char *));
	if (!out)
		return (NULL);
	i = -1;
	j = -1;
	while (s1[i])
		out[i] = s1[i++];
	while (s2[j])
		out[i + j] = s2[j++];
	out[i + j] = '\0';
	ft_free(s1, s2);
	return (out);
}
