/*
** EPITECH PROJECT, 2019
** solver
** File description:
** check_case
*/

#include "solver.h"

int check_case_down(int *status,
        list_t **o_list, list_t **c_list, coord_t *pos)
{
    if (*status == 0) {
        fill_start_list_astar(c_list, *pos,
                initialize_coord(pos->x + 1, pos->y));
        *status = 1;
        return (1);
    }
    fill_start_list_astar(o_list, *pos, initialize_coord(pos->x + 1, pos->y));
    return (0);
}

int check_case_up(int *status, list_t **o_list, list_t **c_list, coord_t *pos)
{
    if (*status == 0) {
        fill_start_list_astar(c_list, *pos,
                initialize_coord(pos->x - 1, pos->y));
        *status = 1;
        return (1);
    }
    fill_start_list_astar(o_list, *pos, initialize_coord(pos->x - 1, pos->y));
    return (0);
}

int check_case_left(int *status,
        list_t **o_list, list_t **c_list, coord_t *pos)
{
    if (*status == 0) {
        fill_start_list_astar(c_list, *pos,
                initialize_coord(pos->x, pos->y - 1));
        *status = 1;
        return (1);
    }
    fill_start_list_astar(o_list, *pos, initialize_coord(pos->x, pos->y - 1));
    return (0);
}

int check_case_right(int *status, list_t **c_list, coord_t *pos, char **maze)
{
    fill_start_list_astar(c_list, *pos,
            initialize_coord(pos->x, pos->y + 1));
    maze[pos->x][pos->y + 1] = 'O';
    *status = 1;
    return (1);
}

int check_case(char **maze, list_t **o_list, list_t **c_list, coord_t *arrive)
{
    int status = 0;
    coord_t pos = {(*c_list)->pos.x, (*c_list)->pos.y};

    if  (pos.y < arrive->y &&
        check_value_case(maze, initialize_coord(pos.x, pos.y + 1)) == 1)
        check_case_right(&status, c_list, &pos, maze);
    if (pos.x < arrive->x &&
        check_value_case(maze, initialize_coord(pos.x + 1, pos.y)) == 1)
        if (check_case_down(&status, o_list, c_list, &pos) == 1)
            maze[pos.x + 1][pos.y] = 'O';
    if (pos.y > 0 &&
        check_value_case(maze, initialize_coord(pos.x, pos.y - 1)) == 1)
        if (check_case_left(&status, o_list, c_list, &pos) == 1)
            maze[pos.x][pos.y - 1] = 'O';
    if (pos.x > 0 &&
        check_value_case(maze, initialize_coord(pos.x - 1, pos.y)) == 1)
        if (check_case_up(&status, o_list, c_list, &pos) == 1)
            maze[pos.x - 1][pos.y] = 'O';
    return ((status == 0) ?
            get_old_possibility(maze, c_list, o_list) : SUCCESS);
}