##
## EPITECH PROJECT, 2018
## 
## File description:
## Makefile
##

NAME	=	generator

NAMETEST=	test

SRC		=	src/check_input.c			\
			src/algo_perfect.c			\
			src/display_free_tab.c		\
			src/find_maze.c				\
			src/perfect_maze.c			\
			src/imperfect_maze.c		\
			src/check_place.c			\
			src/check_direction.c		\
			src/strange_maze.c			\
			main.c

SRCTEST	=	src/check_input.c			\
			src/algo_perfect.c			\
			src/display_free_tab.c		\
			src/find_maze.c				\
			src/perfect_maze.c			\
			src/imperfect_maze.c		\
			src/check_place.c			\
			src/check_direction.c		\
			src/strange_maze.c			\
			tests/unit_test_one.c
			

RMTEST	=	check_input.gcno			\
			algo_perfect.gcno			\
			display_free_tab.gcno		\
			find_maze.gcno				\
			perfect_maze.gcno			\
			imperfect_maze.gcno			\
			check_place.gcno			\
			check_direction.gcno		\
			strange_maze.gcno			\
			unit_test_one.gcno			\
			check_input.gcda			\
			algo_perfect.gcda			\
			display_free_tab.gcda		\
			find_maze.gcda				\
			perfect_maze.gcda			\
			imperfect_maze.gcda			\
			check_place.gcda			\
			check_direction.gcda		\
			strange_maze.gcda			\
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

tests_run:
			$(CCO) $(NAMETEST) $(SRCTEST) $(CFLAGS) $(CRITER)
			./$(NAMETEST)

.PHONY:		all clean fclean re
