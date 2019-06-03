/*
** EPITECH PROJECT, 2019
** solver
** File description:
** error_handling
*/

#include "solver.h"

int error_free_maze(char **maze, int ret)
{
    free_array(maze);
    return (ret);
}

int error_maze_possibility(char **maze, list_t **c_list, list_t **o_list)
{
    free_list(*c_list);
    free_list(*o_list);
    free_array(maze);
    fprintf(stderr, "No solution\n");
    return (0);
}

int analyse_arg(int ac, char **av)
{
    struct stat st;

    if (ac != 2) {
        fprintf(stderr, "Please give a correct number of arguments\n");
        return (ERROR);
    } if (stat(av[1], &st) == -1) {
        fprintf(stderr, "This file doesn't exist\n");
        return (ERROR);
    } if ((S_IRUSR & st.st_mode) == 0 || S_ISREG(st.st_mode) == 0) {
        fprintf(stderr, "Doesn't have permission\n");
        return (ERROR);
    }
    return (get_maze(av[1]));
}

int verif_open_file(int fd)
{
    if (fd == -1) {
        fprintf(stderr, "The file doesn't exist.\n");
        return (ERROR);
    }
    return (SUCCESS);
}