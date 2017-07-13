/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coordinats.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 20:31:06 by rhadiats          #+#    #+#             */
/*   Updated: 2017/02/06 19:23:25 by bsemchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetr	*get_coordinats(char *argv)
{
	char		*buf;
	t_tetr		*s;
	char		ch;

	ch = 'A';
	buf = openfilereturnpointer(argv);
	s = s_t_a(ch, buf, create_list(ch), ft_strlen(buf));
	s = lst_del_first(s);
	modulusof(21, s->next);
	add_previous_list(&s);
	return (s);
}
