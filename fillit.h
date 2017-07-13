/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhadiats <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 18:27:37 by rhadiats          #+#    #+#             */
/*   Updated: 2017/02/08 03:58:14 by bsemchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define INCREMENT4ELEMS(a, b, c, d) a++, b++, c++, d++
# define INCREMENT2ELEMS(a, b) a++, b++
# define SET_TO_ZERO3(a, b, c) a=0, b=0, c=0
# define SET_TO_ZERO4(a, b, c, d) a=0, b=0, c=0, d=0
# define FST_RES_SEC_INCR(a, b) a=0, b=b+1
# define GOD_SAVE_NORMINETTE(a, b) write_coord(a, b), a=a->next
# define BUFSIZE 4096
# define MAXREAD 21
# include "libfil.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>

typedef	struct		s_tetr
{
	struct s_tetr	*next;
	struct s_tetr	*previous;
	short int		x[4];
	short int		xy[4][2];
	short int		offset_x;
	short int		offset_y;
	char			letter;
}					t_tetr;

int					check_lines(const char *str);
int					check_symb(const char *str);
int					check_dots(const char *str);
int					check_rows(const char *str);
int					check_tetriminos(const char *str);
int					check_last_newline(const char *str);
int					check_bytes(int bytes);
int					error_message_no_newline(const char *str);
int					validator(const char *str);
int					count_tetr(char *str);
int					is_in_range(int numb, int max, int min);
int					is_left_row(t_tetr *elem);
int					is_ready_to_convert(t_tetr *elem);
int					no_newline(t_tetr *elem);
int					square_size(int tetr);
int					lstlen(t_tetr *list);
int					optimal_size(t_tetr *elem);
int					check_xy(t_tetr *elem, char **map, int max);
int					check_x_is_not_out(t_tetr *elem, int max);
int					check_y_is_not_out(t_tetr *elem, int max);
char				*openfilereturnpointer(char *argv);
char				**create_square(int size);
char				**sol(t_tetr *el, char **m, int mx, t_tetr *bn);
char				**paint_map(t_tetr *elem);
void				freemap(char **map, int max);
void				fill_square(char **square, int size);
void				convert_1_to_2(t_tetr *elem);
void				move_tetriminos_left(t_tetr *elem);
void				add_previous_list(t_tetr **begin);
void				modulusof(int modulus, t_tetr *elem);
void				print_letters(t_tetr *start);
void				lst_push_back(t_tetr **begin, t_tetr *new_list);
void				write_coord(t_tetr *elem, char **map);
void				delete_char(t_tetr *elem, char **map);
void				print_reverse_lst(t_tetr *go);
t_tetr				*create_list(char letter);
t_tetr				*lst_del_first(t_tetr *begin_list);
t_tetr				*s_t_a(char ch, char *str, t_tetr *start, int size);
t_tetr				*catch_tetrimin(char *str);
t_tetr				*get_coordinats(char *argv);

#endif
