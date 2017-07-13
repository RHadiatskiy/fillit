/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is_not_out.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 20:35:14 by rhadiats          #+#    #+#             */
/*   Updated: 2017/02/06 20:37:14 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_x_is_not_out(t_tetr *elem, int max)
{
	int	x;
	int i;
	int j;

	SET_TO_ZERO3(i, j, x);
	while (i < 4)
	{
		x = elem->xy[i][0] + elem->offset_x;
		if (x >= max)
			return (0);
		i++;
	}
	return (1);
}

int		check_y_is_not_out(t_tetr *elem, int max)
{
	int	y;
	int i;
	int j;

	SET_TO_ZERO3(i, j, y);
	while (i < 4)
	{
		y = elem->xy[i][1] + elem->offset_y;
		if (y >= max)
			return (0);
		i++;
		j = 0;
	}
	return (1);
}
