/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_square.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsemchuk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 23:45:53 by bsemchuk          #+#    #+#             */
/*   Updated: 2017/02/06 18:21:58 by bsemchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	fill_square(char **square, int size)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < size)
	{
		while (j < size)
		{
			square[i][j] = '.';
			j++;
		}
		j = 0;
		i++;
	}
}

char	**create_square(int size)
{
	int		i;
	int		j;
	char	**ret;

	i = 0;
	j = 0;
	ret = (char **)malloc(sizeof(char *) * size + 10);
	ret[size] = NULL;
	while (i < size)
	{
		ret[i] = (char *)malloc(sizeof(char) * size + 10);
		ret[i][size] = '\0';
		i++;
	}
	fill_square(ret, size);
	return (ret);
}
