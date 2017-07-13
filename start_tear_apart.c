/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_tear_apart.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 22:21:43 by rhadiats          #+#    #+#             */
/*   Updated: 2017/02/06 19:26:54 by bsemchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetr	*s_t_a(char ch, char *str, t_tetr *start, int size)
{
	short int		i;
	int				k;
	struct s_tetr	*ret;

	i = 0;
	k = 0;
	while (i < size)
	{
		if (i > size)
			return (start);
		if (i % 21 == 0)
		{
			ret = create_list(ch++);
			k = 0;
		}
		if (str[i] == '#')
		{
			ret->x[k] = i;
			k++;
		}
		if (k % 4 == 0 && k != 0)
			lst_push_back(&start, ret);
		i++;
	}
	return (start);
}

void	add_previous_list(t_tetr **begin)
{
	t_tetr *temp;
	t_tetr *previous;

	temp = *begin;
	while (temp->next)
	{
		previous = temp;
		temp = temp->next;
		temp->previous = previous;
	}
}
