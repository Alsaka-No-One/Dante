/*
** EPITECH PROJECT, 2019
** solver
** File description:
** useful_fonction
*/

#include "solver.h"

void free_list(list_t *list)
{
    list_t *element = list;

    while (list != NULL) {
        list = (list)->next;
        free(element);
        element = list;
    }
}

void free_array(char **maze)
{
    for (int i = 0; maze[i] != NULL; i++)
        free(maze[i]);
    free(maze);
}

int get_nb_col(char *maze)
{
    int x = 0;

    while (maze[x] != '\0')
        x++;
    return (x);
}

int get_nb_line(char **maze)
{
    int x = 0;

    while (maze[x] != NULL)
        x++;
    return (x);
}

coord_t initialize_coord(int x, int y)
{
    coord_t coord = {x, y};

    return (coord);
}