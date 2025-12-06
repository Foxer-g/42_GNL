/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toespino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 11:46:23 by toespino          #+#    #+#             */
/*   Updated: 2025/12/06 18:40:39 by toespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*get_next_line(int fd)
{
	int			red_bytes;
	static char	*stash;
	char		*buffer;
	char		*out;

	buffer = malloc(sizeof(char*) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	red_bytes = 1;
	while (ft_strchr(buffer, '\n') == 0, red_bytes > 0)
	{
		red_bytes = read(fd, buffer, BUFFER_SIZE);
		if (red_bytes < 0)
		{
			buffer = ft_free(buffer, stash);
			return (NULL);
		}
		buffer[red_bytes] = '\0';
		stash = ft_strjoin(stash, buffer);
	}
	out = ft_process(stash);
	return (out);
}
