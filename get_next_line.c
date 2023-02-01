/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/02 12:30:10 by ibehluli      #+#    #+#                 */
/*   Updated: 2023/02/01 11:45:15 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		return (NULL);
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
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
	{
		free(buffer);
		return (NULL);
	}
	buffer = read_line_change_text(fd, buffer);
	if (!buffer)
		return (NULL);
	line = read_line(buffer);
	buffer = ft_change_text(buffer);
	if (buffer && ft_strlen(buffer) == 0)
	{
		free(buffer);
		buffer = NULL;
	}
	return (line);
}
