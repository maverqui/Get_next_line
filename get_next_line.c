/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maverqui <maverqui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 20:02:19 by maverqui          #+#    #+#             */
/*   Updated: 2024/02/12 19:34:53 by maverqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int read_file(int fd, char **stash)
{
	char	*buff;
	int		byte_read;

	buff = malloc(sizeof (char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (0);
	byte_read = 1;
	while (byte_read > 0 && ft_strchr(*stash, '\n') == NULL)
	{
		byte_read = read(fd, buff, BUFFER_SIZE);
		if (byte_read < 0)
			return (free(buff), 0);
		buff[byte_read] = '\0';
		*stash = ft_strjoin(*stash, buff);
	}
	if (byte_read == -1)
		return (free(buff), 0);
	return (free(buff), 1);
}

int take_rest(char **stash, int len)
{
	char*	rest;
	int		i;

	i = 0;
	rest = (char *)malloc(ft_strlen(*stash) - len + 1);
	if (!rest)
		return (0);
	while ((*stash)[i])
	{
		rest[i - len] = (*stash)[i];
		i++;
	}
	rest[i - len] = '\0';
	if (*stash != NULL)
		free (*stash);
	*stash = rest;
	return (1);
}

char *cut_line(char **stash)
{
	int 	len;
	int		i;
	char	*line;

	len = 0;
	if(!(*stash)[len])
		return (NULL);
	while ((*stash)[len] && (*stash)[len] != '\n')
		len++;
	if ((*stash)[len] == '\n')
		len++;
	//prise en compte du \n dans la longueur du malloc
	line = malloc(sizeof(char) * len + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line[i] = (*stash)[i];
		i++;
	}
	line[i] = '\0';
	take_rest(stash, len);
	return (line);
}

char *get_next_line(int fd)
{
	char		*line;
	static char *stash;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!read_file(fd, &stash))
		return (NULL);
	if (!stash)
		return (NULL);
	line = cut_line(&stash);
	return (line);
}
int main()
{
	int fd = open("text", O_RDONLY);
	char *data = NULL;
	while ((data = get_next_line(fd)))
	{
		printf("%s\n", data);
		free(data);
	}
	close(fd);
	return (0);
}
