/*
** EPITECH PROJECT, 2019
** solver
** File description:
** start_astar
*/

#include "solver.h"

int check_value_case(char **maze, coord_t coord)
{
    if (maze[coord.x][coord.y] == 'X' || maze[coord.x][coord.y] == 'O')
        return (0);
    return (1);
}

int start_astar(char **maze)
{
    coord_t arrive = {get_nb_line(maze) - 1, get_nb_col(maze[0]) - 1};
    list_t *c_list = initialize_list();
    list_t *o_list = initialize_list();
    int status = 0;

    maze[0][0] = 'O';
    if (c_list == NULL || o_list == NULL)
        return (84);
    while (status == 0) {
        status = check_case(maze, &o_list, &c_list, &arrive);
        if (status == 0)
            status = check_end(c_list, &arrive);
    }
    if (status == 84)
        return (error_maze_possibility(maze, &c_list, &o_list));
    return (delete_trace(maze, &c_list, &o_list));
}