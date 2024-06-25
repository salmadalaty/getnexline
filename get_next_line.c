/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalaty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 11:02:03 by sdalaty           #+#    #+#             */
/*   Updated: 2024/06/25 12:31:10 by sdalaty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	static int	size = 0;
	static int	position = 0;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	return (readline(fd, buffer, &position, &size));
}
// int main(void)
// {
// 	int fd = open("test.txt",O_RDONLY,O_CREAT);
// 	char *res;

// 	res = get_next_line(fd);

// 	printf("\n%s\n", res);
// 	free(res);

// }
