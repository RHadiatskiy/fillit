# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsemchuk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/11 16:58:53 by bsemchuk          #+#    #+#              #
#    Updated: 2017/02/09 16:34:34 by rhadiats         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJS =	check_last_newline.o \
		check_rows.o \
		check_tetriminos.o \
		error_message_no_newline.o \
		validator.o \
		check_lines.o \
		check_symb.o \
		count_tetr.o \
		create_list.o \
		get_coordinats.o \
		openfilereturnpointer.o \
		start_tear_apart.o \
		check_list_left_upper.o \
		create_square.o \
		solution.o \
		convert_move.o \
		check_is_not_out.o \
		solution_func.o \
		libfil.o \
		main.o

SRC =	check_last_newline.c \
		check_rows.c \
		check_tetriminos.c \
		error_message_no_newline.c \
		validator.c \
		check_lines.c \
		check_symb.c \
		count_tetr.c \
		create_list.c \
		get_coordinats.c \
		openfilereturnpointer.c \
		start_tear_apart.c \
		check_list_left_upper.c \
		create_square.c \
		solution.c \
		convert_move.c \
		check_is_not_out.c \
		solution_func.c \
		libfil.c \
		main.c

FLAGS = -Wall -Wextra -Werror

NAME = fillit

LIBRARY_EXE = libfil.a

LIBRARY_CMD = -lfil

all: $(NAME) 

$(NAME): $(OBJS) $(LIBRARY_EXE)
	@gcc $(FLAGS) $(SRC) -L. $(LIBRARY_CMD) -o $(NAME)

debug: $(OBJS)
	@gcc -g $(FLAGS) $(SRC) -L. $(LIBRARY_CMD) -o $(NAME)

$(LIBRARY_EXE): libfil.o
	@ar rc $(LIBRARY_EXE) libfil.o libfil.h

libfil.o: libfil.c 
	@gcc -c $(FLAGS) libfil.c

check_last_newline.o: check_last_newline.c
	@gcc -c $(FLAGS) check_last_newline.c

check_rows.o: check_rows.c
	@gcc -c $(FLAGS) check_rows.c

check_tetriminos.o: check_tetriminos.c
	@gcc -c $(FLAGS) check_tetriminos.c

error_message_no_newline.o: error_message_no_newline.c
	@gcc -c $(FLAGS) error_message_no_newline.c

validator.o: validator.c
	@gcc -c $(FLAGS) validator.c

check_lines.o: check_lines.c
	@gcc -c $(FLAGS) check_lines.c

check_symb.o: check_symb.c
	@gcc -c $(FLAGS) check_symb.c

count_tetr.o: count_tetr.c
	@gcc -c $(FLAGS) count_tetr.c

create_list.o: create_list.c
	@gcc -c $(FLAGS) create_list.c

get_coordinats.o: get_coordinats.c
	@gcc -c $(FLAGS) get_coordinats.c

openfilereturnpointer.o: openfilereturnpointer.c
	@gcc -c $(FLAGS) openfilereturnpointer.c

start_tear_apart.o: start_tear_apart.c
	@gcc -c $(FLAGS) start_tear_apart.c

check_list_left_upper.o: check_list_left_upper.c
	@gcc -c $(FLAGS) check_list_left_upper.c

create_square.o: create_square.c
	@gcc -c $(FLAGS) create_square.c
		
solution.o: solution.c
	@gcc -c $(FLAGS) solution.c

convert_move.o: convert_move.c
	@gcc -c $(FLAGS) convert_move.c

check_is_not_out.o: check_is_not_out.c
	@gcc -c $(FLAGS) check_is_not_out.c

solution_func.o: solution_func.c
	@gcc -c $(FLAGS) solution_func.c

main.o: main.c
	@gcc -c $(FLAGS) main.c

fclean: clean
	@rm -f $(NAME) $(LIBRARY_EXE)

clean:
	@rm -f $(OBJS)

re: fclean all
