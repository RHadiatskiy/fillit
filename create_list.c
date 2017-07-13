/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemchuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 19:28:21 by bsemchuk          #+#    #+#             */
/*   Updated: 2017/02/06 18:21:09 by bsemchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetr	*create_list(char letter)
{
	t_tetr	*ret;

	ret = (t_tetr *)malloc(sizeof(t_tetr));
	if (!ret)
		return (NULL);
	ret->letter = letter;
	ret->next = NULL;
	ret->previous = NULL;
	return (ret);
}

void	lst_push_back(t_tetr **begin, t_tetr *new_list)
{
	t_tetr *temp;

	temp = *begin;
	if (begin)
	{
		while (temp->next != NULL)
			temp = (t_tetr *)temp->next;
		temp->next = (struct s_tetr *)new_list;
		new_list->next = NULL;
	}
}

t_tetr	*lst_del_first(t_tetr *begin_list)
{
	t_tetr *temp;

	if (!begin_list)
		return (NULL);
	temp = begin_list->next;
	free(begin_list);
	return (temp);
}

void	modulusof(int modulus, t_tetr *elem)
{
	if (elem)
	{
		while (elem)
		{
			elem->x[0] = elem->x[0] % modulus;
			elem->x[1] = elem->x[1] % modulus;
			elem->x[2] = elem->x[2] % modulus;
			elem->x[3] = elem->x[3] % modulus;
			elem = elem->next;
		}
	}
}
