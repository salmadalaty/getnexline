/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdalaty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:40:14 by sdalaty           #+#    #+#             */
/*   Updated: 2024/06/25 12:40:02 by sdalaty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <string.h>
# include <stdint.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*readline(int fd, char *buffer, int *position, int *size);
char	*append(char *line, char c, int len);
int		readbuffer(int fd, char *buffer, int *position, int *size);
#endif
