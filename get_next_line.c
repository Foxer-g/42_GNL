/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toespino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 17:11:08 by toespino          #+#    #+#             */
/*   Updated: 2025/11/17 02:41:53 by toespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*get_next_line(int fd)
{
	char		*out;
	int			i;
	static char	*buffer;
	int			len;
	char		*temp;

	out =  "";
	if (fd < 0 || fd > 1023 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (!buffer)
		i = read(fd, buffer, BUFFER_SIZE);
	else
		i = ft_strlen(buffer);
	if (!i)
		return (NULL);
	len = ft_lenline(buffer);
	if (len == 0)
	{
		buffer = 
	}
}
