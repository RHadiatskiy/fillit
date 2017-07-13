/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 17:10:32 by rhadiats          #+#    #+#             */
/*   Updated: 2017/01/16 21:23:46 by bsemchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		count_tetr(char *str)
{
	unsigned int		i;
	unsigned int		tetr;
	unsigned int		cnt;

	cnt = 0;
	i = 0;
	tetr = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#')
		{
			cnt++;
			if (cnt % 4 == 0)
			{
				cnt = 0;
				tetr++;
			}
		}
		i++;
	}
	return (tetr);
}
