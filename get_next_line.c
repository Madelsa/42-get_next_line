/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelsa <mabdelsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 13:10:15 by mabdelsa          #+#    #+#             */
/*   Updated: 2023/08/15 16:01:58 by mabdelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_buffer(int fd, char *stored)
{
	char	*buff;
	int		chars_read;

	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buff == NULL)
		return (NULL);
	chars_read = 1;
	while (chars_read > 0 && ft_strchr(stored, '\n') == NULL)
	{
		chars_read = read(fd, buff, BUFFER_SIZE);
		if (chars_read == -1 || (chars_read == 0 && (stored == NULL
					|| stored[0] == '\0')))
			return (free(buff), free(stored), NULL);
		buff[chars_read] = '\0';
		stored = ft_strjoin(stored, buff);
	}
	return (free(buff), stored);
}

char	*filter_stored(char *stored)
{
	int		i;
	char	*str;

	i = 0;
	if (stored[0] == '\0')
		return (free(stored), NULL);
	while (stored[i] != '\0' && stored[i] != '\n')
		i++;
	if (stored[i] == '\n' || stored[i] == '\0')
		str = ft_substr(stored, 0, i + 1);
	else
		return (NULL);
	return (str);
}

char	*update_stored(char *stored)
{
	int		i;
	char	*str;

	i = 0;
	while (stored[i] != '\0' && stored[i] != '\n')
		i++;
	if (stored[i] == '\0')
		return (free(stored), NULL);
	str = ft_strdup(stored + i + 1);
	return (free(stored), str);
}

char	*get_next_line(int fd)
{
	static char	*stored = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > 2147483646)
		return (NULL);
	stored = read_buffer(fd, stored);
	if (stored == NULL)
		return (NULL);
	line = filter_stored(stored);
	if (line == NULL)
		return (NULL);
	stored = update_stored(stored);
	return (line);
}
