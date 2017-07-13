/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 20:28:11 by rhadiats          #+#    #+#             */
/*   Updated: 2017/02/06 20:45:14 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		lstlen(t_tetr *list)
{
	int	i;

	i = 0;
	while (list)
	{
		list = list->next;
		i++;
	}
	return (i);
}

int		square_size(int tetr)
{
	int	size;

	size = 2;
	while ((size * size) < (tetr * 4))
		size++;
	return (size);
}

char	**paint_map(t_tetr *elem)
{
	char	**ret;

	ret = create_square(square_size(lstlen(elem)));
	if (ret)
		return (ret);
	return (NULL);
}

int		optimal_size(t_tetr *elem)
{
	int i;

	i = square_size(lstlen(elem));
	return (i);
}

int		check_xy(t_tetr *elem, char **map, int max)
{
	int	x;
	int	y;
	int i;
	int j;

	if (!elem || !map)
		return (0);
	SET_TO_ZERO4(i, j, x, y);
	while (i < 4)
	{
		x = elem->xy[i][j++] + elem->offset_x;
		y = elem->xy[i][j] + elem->offset_y;
		if ((x < max) && (y < max))
		{
			if (map[y][x] != '.')
				return (0);
			i++;
			j = 0;
		}
		else
			return (0);
	}
	return (1);
}
