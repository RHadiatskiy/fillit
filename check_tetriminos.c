/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetriminos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemchuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 20:13:21 by bsemchuk          #+#    #+#             */
/*   Updated: 2017/02/08 02:25:02 by bsemchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_tetriminos(const char *str)
{
	int		connect;

	connect = 0;
	while (*str)
	{
		if (*str == '#')
		{
			if (*(str + 1) == '#')
				connect++;
			if (*(str - 1) == '#')
				connect++;
			if (*(str + 5) == '#')
				connect++;
			if (*(str - 5) == '#')
				connect++;
		}
		str++;
	}
	if (connect == 6 || connect == 8)
		return (0);
	return (1);
}
