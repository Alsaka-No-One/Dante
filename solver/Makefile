##
## EPITECH PROJECT, 2018
## 
## File description:
## Makefile
##

NAME	=	solver

NAMETEST=	test

SRC		=	main.c						\
			src/error_handling.c		\
			src/load_maze.c				\
			src/load_maze_two.c			\
			src/useful_fonctions.c		\
			src/start_astar.c			\
			src/initialize_list.c		\
			src/print_maze.c			\
			src/get_old_possibility.c	\
			src/check_case.c			\
			src/check_end.c

SRCTEST	=	src/error_handling.c		\
			src/load_maze.c				\
			src/load_maze_two.c			\
			src/useful_fonctions.c		\
			src/start_astar.c			\
			src/initialize_list.c		\
			src/print_maze.c			\
			src/get_old_possibility.c	\
			src/check_case.c			\
			src/check_end.c				\
			tests/unit_test_one.c

RMTEST	=	error_handling.gcno			\
			load_maze.gcno				\
			load_maze_two.gcno			\
			useful_fonctions.gcno		\
			start_astar.gcno			\
			initialize_list.gcno		\
			print_maze.gcno				\
			get_old_possibility.gcno	\
			check_case.gcno				\
			check_end.gcno				\
			error_handling.gcda			\
			load_maze.gcda				\
			load_maze_two.gcda			\
			useful_fonctions.gcda		\
			start_astar.gcda			\
			initialize_list.gcda		\
			print_maze.gcda				\
			get_old_possibility.gcda	\
			check_case.gcda				\
			check_end.gcda				\
			unit_test_one.gcno			\
			unit_test_one.gcda

OBJ		=	$(SRC:.c=.o)

CCO		=	gcc -o

LIB		=	-L./lib -lmy

CFLAGS	+= -I./include/

CRITER	=	--coverage -lcriterion

RM		=	rm -rf

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CCO) $(NAME) $(OBJ)

clean :
			$(RM) $(OBJ)
			$(RM) $(RMTEST)

fclean:		clean
			$(RM) $(NAME)
			$(RM) $(NAMETEST)

re:			fclean all

tests_run:
			$(CCO) $(NAMETEST) $(SRCTEST) $(CFLAGS) $(CRITER)
			./$(NAMETEST)

.PHONY:		all clean fclean re
