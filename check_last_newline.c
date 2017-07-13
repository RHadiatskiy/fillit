/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_newlines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 22:06:21 by rhadiats          #+#    #+#             */
/*   Updated: 2017/02/08 01:44:56 by bsemchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_last_newline(const char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n' && str[i + 1] == '\n' && str[i + 2] == '\0')
			return (1);
		else
			i++;
	}
	return (0);
}

int		check_bytes(int bytes)
{
	if (bytes == 21 || bytes == 20 || bytes == 0)
		return (0);
	return (1);
}
