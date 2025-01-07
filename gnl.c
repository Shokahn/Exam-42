/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 00:08:38 by root              #+#    #+#             */
/*   Updated: 2025/01/07 00:28:17 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

char *ft_strdup(char *src)
{
	char *dest;
	int i = 0;
	if (!src)
		return (NULL);
	while(src[i])
		i++;
	dest = malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char *get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE];
	static int buffer_read = 0;
	static int buffer_pos = 0;
	int i = 0;
	char line[70000];

	if (fd < 1 || BUFFER_SIZE <= 0)
		return (NULL);
	while(1)
	{
		if (buffer_pos >= buffer_read)
		{
			buffer_read = read(fd, buffer, BUFFER_SIZE);
			buffer_pos = 0;
			if (buffer_read < 0)
				return (NULL);
			if (buffer_read == 0)
				break;
		}
		if (buffer_pos < buffer_read)
		{
			line[i++] = buffer[buffer_pos];
			if (buffer[buffer_pos++] == '\n')
				break;
		}
	}
	line[i] = '\0';
	if (i == 0)
		return (NULL);
	return (ft_strdup(line));
}

int main()
{
	char *line;
	int fd = open("text.txt", O_RDONLY);
	while(1)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
		if (!line)
			break;
	}
}