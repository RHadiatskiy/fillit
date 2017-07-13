/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 01:23:16 by rhadiats          #+#    #+#             */
/*   Updated: 2017/02/06 20:37:50 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	write_coord(t_tetr *elem, char **map)
{
	int	x;
	int	y;
	int i;
	int j;

	SET_TO_ZERO4(i, j, x, y);
	while (i < 4)
	{
		x = elem->xy[i][j++] + elem->offset_x;
		y = elem->xy[i][j] + elem->offset_y;
		map[y][x] = elem->letter;
		i++;
		j = 0;
	}
}

void	delete_char(t_tetr *elem, char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == elem->letter)
				map[i][j] = '.';
			j++;
		}
		i++;
		j = 0;
	}
}

void	freemap(char **map, int max)
{
	int i;

	i = 0;
	while (i < max)
		free(map[i++]);
	free(map);
}

void	reset_offset(t_tetr *elem)
{
	if (elem)
	{
		elem->offset_x = 0;
		elem->offset_y = 0;
	}
}

char	**sol(t_tetr *el, char **m, int mx, t_tetr *bn)
{
	while (el)
	{
		if (check_xy(el, m, mx) == 1)
			GOD_SAVE_NORMINETTE(el, m);
		else if (check_x_is_not_out(el, mx) == 1)
			el->offset_x = el->offset_x + 1;
		else if (check_y_is_not_out(el, mx) == 1)
			FST_RES_SEC_INCR(el->offset_x, el->offset_y);
		else if (el->previous)
		{
			reset_offset(el);
			el = el->previous;
			delete_char(el, m);
			el->offset_x = el->offset_x + 1;
		}
		else
		{
			freemap(m, mx);
			reset_offset(el);
			m = create_square(++mx);
			el = bn;
		}
	}
	return (m);
}
