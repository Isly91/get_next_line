/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/08 09:46:49 by ibehluli      #+#    #+#                 */
/*   Updated: 2023/02/08 09:54:56 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_change_text(char *text)
{
	size_t	i;
	size_t	e;
	char	*new_text;

	i = 0;
	e = 0;
	while (text && text[i] && text[i] != '\n')
		i++;
	if (!text[i] && text)
		return (free(text), NULL);
	new_text = malloc(sizeof(char) * (ft_strlen(text) - i) + 1);
	if (!new_text)
		return (free(text), NULL);
	i++;
	while (text[i] && text && new_text)
	{
		new_text[e] = text[i];
		e++;
		i++;
	}
	new_text[e] = '\0';
	return (free(text), new_text);
}

char	*read_line(char	*buffer)
{
	int		i;
	char	*line;

	i = 0;
	while (buffer && buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer && buffer[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (line && buffer && buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer && buffer[i] == '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*read_line_change_text(int fd, char *buffer)
{
	int		reading;
	char	*text;

	reading = 1;
	text = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!text)
		return (free(buffer), NULL);
	while (reading != 0 && !ft_strchr(buffer, '\n'))
	{
		reading = read(fd, text, BUFFER_SIZE);
		if (reading == -1)
			return (free(text), free(buffer), NULL);
		if (reading == 0)
			break ;
		text[reading] = '\0';
		buffer = ft_strjoin(buffer, text);
	}
	free(text);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[12288];
	char		*line;

	if (fd < 0 && BUFFER_SIZE < 1)
		return (NULL);
	buffer[fd] = read_line_change_text(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = read_line(buffer[fd]);
	if (!line)
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
		return (NULL);
	}
	buffer[fd] = ft_change_text(buffer[fd]);
	if (buffer[fd] && ft_strlen(buffer[fd]) == 0)
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
	}
	return (line);
}
