/*
** EPITECH PROJECT, 2019
** solver
** File description:
** check_end
*/

#include "solver.h"

int check_end(list_t *c_list, coord_t *arrive)
{
    if (c_list->pos.x == arrive->x && c_list->pos.y == arrive->y)
        return (1);
    return (0);
}