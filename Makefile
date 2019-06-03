##
## EPITECH PROJECT, 2019
## Dante
## File description:
## Makefile
##

all:
		make -C ./generator
		make -C ./solver

clean:
		make clean -C ./generator
		make clean -C ./solver

fclean:		clean
		make fclean -C ./generator
		make fclean -C ./solver

re:		fclean all

tests_run:
			make tests_run -C ./solver
			make tests_run -C ./generator

.PHONY:		all clean fclean re
