/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelsa <mabdelsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 14:50:13 by mabdelsa          #+#    #+#             */
/*   Updated: 2023/08/15 16:07:38 by mabdelsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	*stored[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > 2147483646)
		return (NULL);
	stored[fd] = read_buffer(fd, stored[fd]);
	if (stored[fd] == NULL)
		return (NULL);
	line = filter_stored(stored[fd]);
	if (line == NULL)
		return (NULL);
	stored[fd] = update_stored(stored[fd]);
	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	int		fd1;
// 	int		fd2;
// 	char	*line;

// 	fd = open("file.txt", O_RDONLY);
// 	fd1 = open("file1.txt", O_RDONLY);
// 	fd2 = open("file2.txt", O_RDONLY);
// 	line = get_next_line(fd);
// 	while (line)
// 	{
// 		printf("FD: %d, LINE: %s\n", fd, line);
// 		free(line);
//         line = get_next_line(fd1);
//         printf("FD: %d, LINE: %s\n", fd1, line);
// 		free(line);
//         line = get_next_line(fd2);
//          printf("FD: %d, LINE: %s\n", fd2, line);
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// }
