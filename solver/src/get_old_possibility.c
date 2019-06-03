/*
** EPITECH PROJECT, 2019
** solver
** File description:
** get_old_possibility
*/

#include "solver.h"

int get_old_possibility(char **maze, list_t **c_list, list_t **o_list)
{
    list_t *o_element = (*o_list)->next;
    list_t *c_element = (*c_list);

    if ((*o_list)->pos.x == 0 && (*o_list)->pos.y == 0)
        return (ERROR);
    while (*c_list != NULL) {
        if ((*c_list)->pos.x == (*o_list)->parent.x
            && (*c_list)->pos.y == (*o_list)->parent.y) {
            maze[(*o_list)->pos.x][(*o_list)->pos.y] = 'O';
            (*o_list)->next = *c_list;
            *c_list = *o_list;
            *o_list = o_element;
            return (SUCCESS);
        }
        *c_list = (*c_list)->next;
        free(c_element);
        c_element = *c_list;
    }
    return (ERROR);
}