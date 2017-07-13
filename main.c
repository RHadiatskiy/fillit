/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 16:45:38 by rhadiats          #+#    #+#             */
/*   Updated: 2017/02/06 21:12:26 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	t_tetr	*coord;
	char	**map;
	int		i;
	int		mx;

	i = 0;
	if (argc != 2)
		error_message_no_newline("usage: ./fillit [reading_file]\n");
	if (validator(argv[1]) == 1)
		return (1);
	coord = get_coordinats(argv[1]);
	move_tetriminos_left(coord);
	convert_1_to_2(coord);
	mx = optimal_size(coord);
	map = sol(coord, paint_map(coord), mx, coord);
	while (map[i])
	{
		ft_putstr(map[i++]);
		write(1, "\n", 1);
	}
	return (0);
}
