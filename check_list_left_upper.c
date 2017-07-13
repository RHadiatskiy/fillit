/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_list_left_upper.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemchuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 20:23:11 by bsemchuk          #+#    #+#             */
/*   Updated: 2017/02/06 20:46:33 by rhadiats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		is_in_range(int numb, int max, int min)
{
	if (numb <= max && numb >= min)
		return (1);
	return (0);
}

int		no_newline(t_tetr *elem)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (elem->x[i] == 4 || \
			elem->x[i] == 9 || \
			elem->x[i] == 14 || \
			elem->x[i] == 19)
			return (0);
		i++;
	}
	return (1);
}

int		is_upper_row(t_tetr *elem)
{
	if (is_in_range((int)elem->x[0], 3, 0) == 1)
		return (1);
	return (0);
}

int		is_left_row(t_tetr *elem)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (elem->x[i++] % 5 == 0)
			return (1);
	}
	return (0);
}

int		is_ready_to_convert(t_tetr *elem)
{
	if (is_upper_row(elem) == 0)
		return (0);
	if (is_left_row(elem) == 0)
		return (0);
	if (no_newline(elem) == 0)
		return (0);
	return (1);
}
