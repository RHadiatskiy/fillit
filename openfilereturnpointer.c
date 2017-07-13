/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   openfilereturnpointer.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 20:49:23 by rhadiats          #+#    #+#             */
/*   Updated: 2017/01/28 01:06:38 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*openfilereturnpointer(char *argv)
{
	char	*buf;
	int		fd;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		error_message_no_newline("error\n");
	buf = (char *)malloc(sizeof(char) * BUFSIZE);
	if (read(fd, buf, BUFSIZE) == -1)
		error_message_no_newline("error\n");
	return (buf);
}
