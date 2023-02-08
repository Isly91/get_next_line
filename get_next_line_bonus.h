/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.h                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/08 09:48:12 by ibehluli      #+#    #+#                 */
/*   Updated: 2023/02/08 09:49:00 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*read_line_change_text(int fd, char *buffer);
char	*ft_strchr(char *s, int c);
size_t	ft_strlen(char *s);
char	*read_line(char	*buffer);
char	*ft_change_text(char *text);
char	*ft_strjoin(char *s1, char *s2);

#endif