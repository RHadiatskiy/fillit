/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 16:19:03 by rhadiats          #+#    #+#             */
/*   Updated: 2017/02/08 01:48:22 by bsemchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		if_more_than_26_tetr_validation(const char *arg)
{
	char	*buf;

	buf = openfilereturnpointer((char *)arg);
	if (count_tetr(buf) > 26)
		error_message_no_newline("error\n");
	if (check_last_newline(buf) == 1)
		error_message_no_newline("error\n");
	return (0);
}

int		validator(const char *arg)
{
	int		fd;
	int		bts;
	char	buf[BUFSIZE];

	bts = 1;
	fd = open(arg, O_RDONLY);
	if (fd == -1)
		error_message_no_newline("error\n");
	while (bts != 0)
	{
		bts = read(fd, buf, 21);
		if (check_rows(buf) == 1 || \
			check_lines(buf) == 1 || \
			check_dots(buf) == 1 || \
			check_symb(buf) == 1 || \
			check_tetriminos(buf) == 1 || \
			check_bytes(bts) == 1)
			error_message_no_newline("error\n");
	}
	if_more_than_26_tetr_validation(arg);
	close(fd);
	return (0);
}
