/*
** EPITECH PROJECT, 2019
** solver
** File description:
** initialize_list
*/

#include "solver.h"

list_t *initialize_list(void)
{
    list_t *list = malloc(sizeof(list_t));

    if (list == NULL)
        return (NULL);
    list->parent.x = 0;
    list->parent.y = 0;
    list->pos.x = 0;
    list->pos.y = 0;
    list->next = NULL;
    return (list);
}

void fill_start_list_astar(list_t **list, coord_t parent, coord_t pos)
{
    list_t *element = malloc(sizeof(list_t));

    if (element == NULL)
        return;
    element->parent.x = parent.x;
    element->parent.y = parent.y;
    element->pos.x = pos.x;
    element->pos.y = pos.y;
    element->next = *list;
    *list = element;
}