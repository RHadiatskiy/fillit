/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 22:17:12 by rhadiats          #+#    #+#             */
/*   Updated: 2017/02/06 18:24:22 by bsemchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_lst(t_tetr *go)
{
	t_tetr	*temp;

	temp = go;
	if (go)
	{
		while (temp->next != NULL)
			temp = temp->next;
		while (temp != NULL)
		{
			free(temp->next);
		}
		free(go);
	}
}
