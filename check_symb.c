/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_symb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 17:15:22 by rhadiats          #+#    #+#             */
/*   Updated: 2017/02/06 21:18:15 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_symb(const char *str)
{
	unsigned int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '.' || str[i] == '#' || str[i] == '\n')
			i++;
		else
			return (1);
	}
	return (0);
}

int		check_dots(const char *str)
{
	int i;
	int c;

	c = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i++] == '.')
			c++;
	}
	if (c % 12 == 0)
		return (0);
	else
		return (1);
}
