/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 20:18:56 by rhadiats          #+#    #+#             */
/*   Updated: 2017/02/06 20:48:04 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	convert_1_to_2(t_tetr *elem)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (elem)
	{
		while (i < 4)
		{
			elem->xy[i][0] = elem->x[i] % 5;
			elem->xy[i][1] = elem->x[i] / 5;
			i++;
		}
		i = 0;
		elem = elem->next;
	}
}

void	move_tetriminos_left(t_tetr *elem)
{
	int	i;

	i = 0;
	while (elem)
	{
		if (is_ready_to_convert(elem) == 1)
			elem = elem->next;
		else
		{
			while (is_ready_to_convert(elem) != 1)
			{
				while (i < 4)
				{
					elem->x[i] = elem->x[i] - 1;
					i++;
				}
				i = 0;
			}
			elem = elem->next;
		}
	}
}
