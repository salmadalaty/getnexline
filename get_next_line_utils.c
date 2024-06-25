/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalaty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 13:06:41 by sdalaty           #+#    #+#             */
/*   Updated: 2024/06/25 12:03:49 by sdalaty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	readbuffer(int fd, char *buffer, int *position, int *size)
{
	*size = read(fd, buffer, BUFFER_SIZE);
	*position = 0;
	return (*size);
}

char	*readline(int fd, char *buffer, int *position, int *size)
{
	char	*line;
	char	c;
	int		line_len;

	line = NULL;
	line_len = 0;
	while (1)
	{
		if (*position >= *size)
		{
			if (readbuffer(fd, buffer, position, size) <= 0)
			{
				if (line_len > 0)
					return (line);
				free(line);
				return (NULL);
			}
		}
		c = buffer[(*position)++];
		line = append(line, c, line_len++);
		if (c == '\n' || !line)
			break ;
	}
	return (line);
}

char	*append(char *line, char c, int len)
{
	char	*new_line;
	int		i;

	new_line = (char *)malloc(len + 2);
	if (!new_line)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new_line[i] = line[i];
		i++;
	}
	new_line[len] = c;
	new_line[len + 1] = '\0';
	free(line);
	return (new_line);
}
