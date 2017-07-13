/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 17:17:35 by rhadiats          #+#    #+#             */
/*   Updated: 2017/01/28 00:52:35 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_lines(const char *str)
{
	unsigned int		i;
	unsigned int		ln;
	unsigned int		point;
	unsigned int		hashtag;

	i = 0;
	ln = 0;
	point = 0;
	hashtag = 0;
	while ((str[i] || str[i] != '\n' || str[i - 1] != '\n') && i < MAXREAD)
	{
		if (str[i] == '\n')
			ln++;
		if (str[i] == '.')
			point++;
		if (str[i] == '#')
			hashtag++;
		i++;
	}
	if (point == 12 || hashtag == 4 || ln == 4)
		return (0);
	return (1);
}
