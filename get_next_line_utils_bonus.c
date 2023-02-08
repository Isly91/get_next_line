/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils_bonus.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/08 09:47:55 by ibehluli      #+#    #+#                 */
/*   Updated: 2023/02/08 09:47:58 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_str;
	size_t	i;
	size_t	j;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	new_str = malloc(sizeof (char) * (i + j + 1));
	if (!new_str)
		return (free(s1), NULL);
	new_str[i + j] = '\0';
	while (j--)
		new_str[i + j] = s2[j];
	while (i--)
		new_str[i] = s1[i];
	if (s1)
		free(s1);
	return (new_str);
}

char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (free(str), NULL);
	while (str && str[i] != '\0')
	{
		if (str[i] == (char)c)
			return (&str[i]);
		i++;
	}
	return (NULL);
}
