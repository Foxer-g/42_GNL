/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toespino <toespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 19:21:36 by toespino          #+#    #+#             */
/*   Updated: 2025/12/07 22:14:56 by toespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif
# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_free(char *s1, char *s2);
int		ft_strlen(char *str);
int		ft_strchr(char *str, int c);
char	*ft_strjoin(char *s1, char *s2);

#endif
