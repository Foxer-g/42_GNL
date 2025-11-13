/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toespino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 17:11:08 by toespino          #+#    #+#             */
/*   Updated: 2025/11/13 17:54:36 by toespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*get_next_line(int fd)
{
	char		*out;
	static int	i = 0;
	static char	

	out =  "";
	if (fd < 0 || fd > 1023)
		return (NULL);
	if (!i)
		i = read(fd, red, BUFFER_SIZE);
	ft_check
}
